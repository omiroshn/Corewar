/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:48:52 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 14:06:34 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_strsplit(const char *s, char c, int *num_words)
{
	int		i;
	int		j;
	char	**result;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	*num_words = ft_countwords(s, c);
	if (!(result = (char**)malloc(sizeof(result) * (*num_words + 2))))
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (j < *num_words && s[i])
	{
		result[j] = ft_getword((char*)s, c, &i);
		j++;
	}
	result[j] = NULL;
	return (result);
}

char	**ft_strssplit(const char *s, char *c, int *num_words)
{
	int		i;
	int		j;
	char	**result;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	*num_words = ft_countwordss(s, c);
	if (!(result = (char**)malloc(sizeof(result) * (*num_words + 1))))
		return (NULL);
	while (ft_strchr(c, s[i]) != NULL && s[i])
		i++;
	while (j < *num_words && s[i])
	{
		result[j] = ft_getsword(s, c, &i);
		j++;
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split_once(const char *s, char *split_char, char *skip_chars)
{
	char		**ret;
	const char	*token1_end;
	size_t		s_len;
	size_t		token_len;

	while (ft_strchr(skip_chars, *s))
		++s;
	s_len = ft_strlen(s);
	token_len = ft_strslen(s, split_char);
	if (s_len == token_len)
		return (NULL);
	ret = malloc(sizeof(char*) * 3);
	ret[0] = malloc(token_len + 1);
	ft_strncpy(ret[0], s, token_len);
	ret[0][token_len] = '\0';
	s += token_len;
	token1_end = s;
	while (ft_strchr(skip_chars, *s) != NULL)
		s++;
	token_len = s_len - token_len - (s - token1_end);
	ret[1] = malloc(token_len + 1);
	ft_strncpy(ret[1], s, token_len);
	ret[1][token_len] = '\0';
	ret[2] = NULL;
	return (ret);
}

void	ft_strsplit_release(char **words, int num_words)
{
	if (words == NULL || num_words == 0)
		return ;
	while (num_words--)
		free(words[num_words]);
	free(words);
}
