/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/16 14:24:12 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# include <stdbool.h>
# include <stdarg.h>

typedef enum	e_length_type
{
	none_length = 0,
	hh_length, h_length,
	l_length, ll_length,
	j_length, z_length,
	length_types_total,
	ptrdiff_t_length,
	L_length
}				t_length_type;

struct			s_flags
{
	bool		left_justification;
	bool		force_sign_preceding;
	bool		put_space_instead_of_sign;
	bool		special;
	bool		padding_with_zeros;
};

struct s_specifier;

char			*parse_sub_specifiers(char *s, struct s_specifier *spec,
															va_list ap);
char			*parse_min_width(char *s, struct s_specifier *spec,
															va_list ap);
char			*parse_precision(char *s, struct s_specifier *spec,
															va_list ap);
char			*parse_length_type(char *s, t_length_type *type);

#endif
