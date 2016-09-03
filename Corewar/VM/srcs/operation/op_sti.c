/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 18:06:47 by sdelardi          #+#    #+#             */
/*   Updated: 2016/07/19 17:27:22 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	op_sti(t_proc *proc)
{
	int n;
	int n2;
	int n3;

	if (proc->params.mode[1] == M_IND)
		n2 = proc->params.param[1];
	else if (!get_param(proc, 1, &n2))
		return ;
	if (proc->params.mode[2] == M_IND)
		n3 = proc->params.param[2];
	else if (!get_param(proc, 2, &n3))
		return ;
	if (get_param(proc, 0, &n))
	{
		write_in_ram(proc->start, proc->pc + ((n2 + n3) % IDX_MOD), n,
				proc->no);
	}
}
