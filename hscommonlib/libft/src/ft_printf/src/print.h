/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:32:18 by admin             #+#    #+#             */
/*   Updated: 2018/06/16 14:35:08 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdarg.h>
# include <inttypes.h>
# include <stdbool.h>
# include <wchar.h>
# include <wctype.h>

# define ABS(v) ((v) < 0 ? -(v) : (v))
# define MAX(a, b) ((a) > (b) ? (a) : (b))
# define MIN(a, b) ((a) < (b) ? (a) : (b))

struct s_specifier;

int		handle_integer_precision(struct s_specifier *spec, char **res,
							int size, bool value_is_zero);

void	print_signed_integer(struct s_specifier *spec, va_list ap);
void	print_unsigned_integer(struct s_specifier *spec, va_list ap);
void	print_pointer(struct s_specifier *spec, va_list ap);
void	print_hexa(struct s_specifier *spec, va_list ap, bool upper_case);
void	print_octa(struct s_specifier *spec, va_list ap, bool upper_case);
void	print_binary(struct s_specifier *spec, va_list ap, bool upper_case);
void	print_float(struct s_specifier *spec, va_list ap, bool upper_case);
void	print_scientific(struct s_specifier *s, va_list ap, bool upper_case);
void	print_shortest_float(struct s_specifier *s, va_list ap, bool up_case);

char	*ft_itoa_base(intmax_t number, int base, int *size);
char	*ft_uitoa_base(uintmax_t number, int base, int *size);

int		print_wchar_to_buffer(wchar_t wchar, char buf[4]);
int		wchar_len(wchar_t wchar);

void	print_character(struct s_specifier *spec, va_list ap);
void	print_string(struct s_specifier *spec, va_list ap);

void	print(struct s_specifier *spec, void *str, int size, bool freeing);

#endif
