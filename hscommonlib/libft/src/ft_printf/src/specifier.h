/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/16 15:04:28 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIER_H
# define SPECIFIER_H

# include "flags.h"

# include <stdarg.h>

# define PRECISION_NOT_SET -1

struct	s_specifier
{
	struct s_flags	flags;
	t_length_type	length_type;
	int				min_width;
	int				precision;
	char			symb;
};

char	*process_specifier(char *format, va_list ap);

extern const char *g_number_specifiers;

#endif
