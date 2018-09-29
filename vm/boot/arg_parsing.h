/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 13:16:27 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 13:17:12 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_PARSING_H
# define ARG_PARSING_H

# include <stdbool.h>

struct s_vm;

bool	parse_args(struct s_vm *vm, int ac, char **av);

#endif
