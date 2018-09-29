/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_post_proc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 19:54:43 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/16 14:43:53 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"

void	post_proc_death(
			int32_t proc_id)
{
	EVENT_DECL(kEventProcessDeath);
	event.info.pd.proc_id = proc_id;
	post_event(&event);
}

void	post_proc_write(
			int32_t player_id,
			int32_t value,
			uint16_t memory_pool_position)
{
	EVENT_DECL(kEventProcessWrite);
	event.info.wr.master_id = player_id;
	event.info.wr.position = memory_pool_position;
	event.info.wr.value = value;
	post_event(&event);
}

void	post_proc_move(
			int32_t proc_id,
			uint16_t new_position)
{
	EVENT_DECL(kEventProcessMove);
	event.info.mv.position = new_position;
	event.info.mv.proc_id = proc_id;
	post_event(&event);
}

void	post_proc_create(
			int32_t player_id,
			int32_t proc_id,
			uint16_t position)
{
	EVENT_DECL(kEventProcessCreate);
	event.info.pc.player_id = player_id;
	event.info.pc.position = position;
	event.info.pc.proc_id = proc_id;
	post_event(&event);
}
