/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:22:36 by hshakula          #+#    #+#             */
/*   Updated: 2018/06/16 14:10:55 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>

int	ft_printf(const char *format, ...) __printflike(1, 2);
int	ft_dprintf(int fd, const char *format, ...) __printflike(2, 3);
int	ft_snprintf(char *dst, size_t size,
				const char *format, ...) __printflike(3, 4);

#endif
