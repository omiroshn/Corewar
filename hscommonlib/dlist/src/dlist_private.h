/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:28:17 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 13:59:40 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_PRIVATE_H
# define DLIST_PRIVATE_H

# include "dlist.h"
# include <stdlib.h>

struct				s_dlist_node
{
	void				*data;
	struct s_dlist_node	*next;
	struct s_dlist_node	*previous;
};

struct s_dlist_node	*remove_node(
						struct s_dlist_node *node,
						void (*del)(void *data),
						struct s_dlist *list);

#endif
