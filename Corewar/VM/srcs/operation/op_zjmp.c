/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 18:00:49 by sdelardi          #+#    #+#             */
/*   Updated: 2016/07/19 17:28:08 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_zjmp(t_proc *proc)
{
	if (proc->carry)
	{
		proc->pc += proc->params.param[0];
	}
	else
	{
		proc->pc += proc->params.step;
	}
}
