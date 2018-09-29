/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Admin <Admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 12:44:10 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/16 00:57:24 by Admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_FUNCS_H
# define KEY_FUNCS_H

# include <stdlib.h>

size_t	hash_string(const void *key);
int		compare_string(const void *a, const void *b);
void	*alloc_string(const void *key);

size_t	hash_int(const void *key);
int		compare_int(const void *lhs, const void *rhs);

#endif
