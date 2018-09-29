/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_line_label.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:29:03 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 13:29:49 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_line.h"
#include "op_line_label.h"
#include "libft.h"
#include <stdlib.h>

char			*op_line_parse_label(struct s_op_line *line)
{
	char	*s;
	char	*label_end;

	if ((label_end = ft_strchr(line->str, LABEL_CHAR)))
	{
		if (label_end == line->str)
			return (NULL);
		s = line->str;
		while (s != label_end)
		{
			if (ft_strchr(LABEL_CHARS, *s) == NULL)
				return (line->str);
			++s;
		}
		line->type = kOpLineTypeLabel;
		line->c.lop.l.str = malloc(label_end - line->str + 1);
		ft_strncpy(line->c.lop.l.str, line->str, label_end - line->str);
		line->c.lop.l.str[label_end - line->str] = '\0';
		label_end++;
	}
	else
		label_end = line->str;
	return (label_end);
}
