/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_file_disassemble.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:27:04 by admin             #+#    #+#             */
/*   Updated: 2018/09/09 13:32:08 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COR_FILE_DISASSEMBLE_H
# define COR_FILE_DISASSEMBLE_H

# include <stdbool.h>
# include <inttypes.h>
# include <stddef.h>

struct s_cor_file;

bool	cor_file_disassemble(
			struct s_cor_file *cor_file,
			int output_fd);

#endif
