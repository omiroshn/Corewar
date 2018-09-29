/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 19:12:17 by hshakula          #+#    #+#             */
/*   Updated: 2018/06/19 20:13:05 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
	return ;
}

void	free_array_of_strings(char ***words)
{
	char **w_words;
	char ***ww_words;

	if (*words == NULL)
		return ;
	ww_words = words;
	w_words = *words;
	while (*w_words)
	{
		if (*w_words != NULL)
			free(*w_words);
		w_words++;
	}
	free(*ww_words);
	*ww_words = NULL;
}
