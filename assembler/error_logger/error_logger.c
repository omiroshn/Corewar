/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_logger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 23:01:45 by admin             #+#    #+#             */
/*   Updated: 2018/09/05 23:12:34 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_logger.h"
#include "dlist.h"
#include <stdlib.h>

struct s_dlist	*g_error_list = NULL;

void				log_error_s(struct s_error_desc desc)
{
	struct s_error_desc	*err;

	if (g_error_list == NULL)
		g_error_list = dlist_new();
	err = malloc(sizeof(struct s_error_desc));
	*err = desc;
	dlist_push_back_data(g_error_list, err);
}

inline void			log_error(
						int line,
						struct s_error_str msg,
						struct s_error_str file)
{
	log_error_s((struct s_error_desc){line, msg, file});
}

struct s_dlist		*log_fflush(void)
{
	struct s_dlist *ret;

	ret = g_error_list;
	g_error_list = NULL;
	return (ret);
}

void				log_release_err(void *err_ptr)
{
	struct s_error_desc *err;

	err = err_ptr;
	if (err->file.free)
		free(err->file.s);
	if (err->msg.free)
		free(err->msg.s);
	free(err_ptr);
}
