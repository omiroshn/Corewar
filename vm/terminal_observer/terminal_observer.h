/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_observer.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 20:49:17 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/22 12:42:37 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_OBSERVER_H
# define TERMINAL_OBSERVER_H

# include <stdbool.h>

void	register_terminal_observer(bool verbose);
void	unregister_terminal_observer(void);

#endif
