/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_logger_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 23:24:31 by admin             #+#    #+#             */
/*   Updated: 2018/09/05 23:24:37 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_logger_print.h"
#include "error_logger.h"
#include "ft_printf.h"
#include "dlist.h"

static void	print_err(void *err_ptr, void *ctx)
{
	const struct s_error_desc *err = err_ptr;

	if (err->line != -1)
	{
		ft_dprintf(2, "%s: line %d: {red}error{eoc}: %s\n",
					err->file.s, err->line, err->msg.s);
	}
	else
		ft_dprintf(2, "%s: {red}%s{eoc}\n", err->file.s, err->msg.s);
}

void		print_error_list(struct s_dlist *err_list)
{
	if (err_list)
		dlist_iterate(err_list, print_err, NULL);
}
