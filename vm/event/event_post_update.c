/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_post_update.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:48:43 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/22 13:49:32 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

void	post_ui_update(
			bool paused,
			int update_speed)
{
	EVENT_DECL(kEventUiUpdate);
	event.info.uu.paused = paused;
	event.info.uu.update_speed = update_speed;
	post_event(&event);
}

void	post_check_up(
			uint16_t cycles_to_die,
			uint8_t num_checkups_wo_decrease)
{
	EVENT_DECL(kEventCheckUp);
	event.info.cu.cycles_to_die = cycles_to_die;
	event.info.cu.num_checkups_wo_decrease = num_checkups_wo_decrease;
	post_event(&event);
}
