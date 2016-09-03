/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 16:44:10 by sdelardi          #+#    #+#             */
/*   Updated: 2016/07/19 17:24:38 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	op_fork(t_proc *proc)
{
	t_proc			*new;
	t_champ			*champ;

	new = ft_memalloc(sizeof(t_proc));
	new->start = (proc->start + proc->pc + (proc->params.param[0] % IDX_MOD))
					% MEM_SIZE;
	new->id = ++g_vm.id;
	ft_memcpy(new->reg, proc->reg, REG_SIZE * REG_NUMBER);
	new->carry = proc->carry;
	new->no = proc->no;
	new->cycles = 0;
	champ = get_champ_by_no(proc->no);
	champ->proc += 1;
	op_controller(new);
	ft_lst_push_front(g_vm.procs, (void*)new);
}
