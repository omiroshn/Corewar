/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_controller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:10:56 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/22 13:19:12 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_controller.h"
#include "curses.h"
#include "timer.h"
#include "libft.h"
#include "vm.h"

#define CLAMP(v, e0, e1) ((v) < (e0) ? (e0) : ((v) > (e1) ? (e1) : (v)))

struct s_vm_controller	*vm_controller_init(struct s_vm *vm)
{
	struct s_vm_controller	*ret;

	ret = ft_memalloc(sizeof(struct s_vm_controller));
	ret->vm = vm;
	ret->update_speed = 50;
	init_timer(&ret->timer);
	post_ui_update(ret->paused, ret->update_speed);
	return (ret);
}

bool					vm_should_update_game(
							struct s_vm_controller *self)
{
	const double estimated_time = 1.0 / self->update_speed;
	const double dt = delta_time_from(&self->timer, self->last_update_time);

	if (self->vm->cfg.ui != kUiTypeNcurses)
		return (true);
	if (!self->paused && dt > estimated_time)
	{
		self->last_update_time = current_time(&self->timer);
		return (true);
	}
	return (false);
}

static const char	*g_processed_key = "qwer ";

void					vm_controller_read_input(
							struct s_vm_controller *self)
{
	int		key;
	bool	data_updated;

	data_updated = false;
	if (self->vm->cfg.ui != kUiTypeNcurses)
		return ;
	while ((key = curses_get_event_key()) != kCursesKeyNone)
	{
		if (ft_strchr(g_processed_key, key))
		{
			if (key == 'r')
				self->update_speed += 10;
			else if (key == 'e')
				self->update_speed++;
			else if (key == 'w')
				self->update_speed--;
			else if (key == 'q')
				self->update_speed -= 10;
			else if (key == ' ')
				self->paused = !self->paused;
			data_updated = true;
		}
	}
	if (data_updated)
	{
		self->update_speed = CLAMP(self->update_speed, 1, 1000);
		post_ui_update(self->paused, self->update_speed);
	}
}

void					vm_controller_release(
							struct s_vm_controller *self)
{
	free(self);
}
