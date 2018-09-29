/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:46:39 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/04 17:55:18 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_PARSER_H
# define TOKEN_PARSER_H

# include "token_parser_args.h"

void				token_parser_init(void);
void				token_parser_deinit(void);
t_operation_type	token_parse_op_type(char *token);

#endif
