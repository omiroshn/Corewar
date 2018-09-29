/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 12:07:31 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 12:52:43 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include <stdbool.h>

struct s_vm;

bool	vm_init(struct s_vm *vm, int ac, char **av);
void	print_usage(const char *exec_name, const char *error_msg);

#endif
