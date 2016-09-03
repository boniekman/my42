/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 17:35:11 by sdelardi          #+#    #+#             */
/*   Updated: 2016/07/19 17:28:40 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	write_in_ram(int start, int index, int n, int no)
{
	g_vm.ram[(start + index) % MEM_SIZE] = n >> 24;
	g_vm.ram[(start + index + 1) % MEM_SIZE] = (n >> 16) & 0xff;
	g_vm.ram[(start + index + 2) % MEM_SIZE] = (n >> 8) & 0xff;
	g_vm.ram[(start + index + 3) % MEM_SIZE] = n & 0xff;
	if (g_vm.vizu)
		vwrite_mem(no, &n, (start + index) % MEM_SIZE, sizeof(n));
}

void	op_st(t_proc *proc)
{
	int		n;
	int		n2;

	if (proc->params.mode[1] == M_IND)
	{
		n2 = proc->PARAM[1];
		if (get_param(proc, 0, &n))
		{
			write_in_ram(proc->start, proc->pc + (n2 % IDX_MOD), n, proc->no);
		}
	}
	else
	{
		if (get_param(proc, 0, &n) && 0 < proc->PARAM[1] && proc->PARAM[1] < 17)
		{
			store_registre(proc->reg[proc->PARAM[1] - 1], n);
		}
	}
}
