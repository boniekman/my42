/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 17:03:31 by sdelardi          #+#    #+#             */
/*   Updated: 2016/07/19 17:25:22 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	op_lfork(t_proc *proc)
{
	t_proc			*new;
	t_champ			*champ;

	new = ft_memalloc(sizeof(t_proc));
	new->start = (proc->start + proc->pc + proc->params.param[0]) % MEM_SIZE;
	ft_memcpy(new->reg, proc->reg, REG_SIZE * REG_NUMBER);
	new->carry = proc->carry;
	new->id = ++g_vm.id;
	new->no = proc->no;
	champ = get_champ_by_no(proc->no);
	champ->proc += 1;
	op_controller(new);
	ft_lst_push_front(g_vm.procs, (void*)new);
	proc->carry = 1;
}
