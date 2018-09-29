/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Admin <Admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 22:48:30 by Admin             #+#    #+#             */
/*   Updated: 2018/09/03 23:17:57 by Admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "dlist.h"
# include "job.h"

typedef enum		e_job_type
{
	kJobStandard = 0,
	kJobDisassemble,
	kJobTypesTotal
}					t_job_type;

struct				s_asm
{
	struct s_dlist	job_list;
	t_job_type		job_type;
};

#endif
