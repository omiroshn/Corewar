/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_logger_print.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 23:01:49 by admin             #+#    #+#             */
/*   Updated: 2018/09/09 13:30:39 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_LOGGER_PRINT_H
# define ERROR_LOGGER_PRINT_H

# include <stdbool.h>

struct s_dlist;

void	print_error_list(struct s_dlist *err_list);

#endif
