/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_controller.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:10:57 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/22 13:20:28 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_CONTROLLER_H
# define VM_CONTROLLER_H

# include "timer.h"

# include <inttypes.h>
# include <stdbool.h>

struct s_vm;

struct					s_vm_controller
{
	struct s_vm			*vm;
	t_timer				timer;
	bool				paused;
	int					update_speed;
	uint64_t			last_update_time;
};

struct s_vm_controller	*vm_controller_init(struct s_vm *vm);
void					vm_controller_read_input(
							struct s_vm_controller *controller);
bool					vm_should_update_game(
							struct s_vm_controller *controller);
void					vm_controller_release(
							struct s_vm_controller *controller);

#endif
