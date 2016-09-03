/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_ram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 13:38:37 by akpenou           #+#    #+#             */
/*   Updated: 2016/07/19 18:06:38 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** static int			set_starting_point(t_champ *champ, int start)
** {
** t_proc *proc;
** unsigned int id;
**
** id = reverse_int(champ->id);
** if ((proc = ft_memalloc(sizeof(t_proc))) == NULL)
** fatal_exit_vm("critical error -> malloc failed");
** proc->name = ft_strdup(champ->name);
** proc->start = start;
** ft_memcpy(proc->reg[0], &id, sizeof(unsigned int));
** ft_lst_push_back(champ->proc, (void*)proc);
** return (1);
** }
*/

static int			init_ram_(t_champ *champ, int *counter)
{
	int				max;
	unsigned int	id;
	t_proc			*proc;

	id = reverse_int(champ->id);
	max = ft_lst_len(g_vm.champs);
	champ->no = max - *counter + 1;
	champ->proc = 1;
	ft_memcpy(&(g_vm.ram[(4 - 4 * (*counter) / max) * 1024]), champ->body,
			champ->size);
	if (!(proc = ft_memalloc(sizeof(t_proc))))
		fatal_exit_vm("critical error -> allocation failed");
	proc->start = (4 - 4 * (*counter) / max) * 1024;
	proc->no = champ->no;
	proc->id = ++g_vm.id;
	proc->alive = false;
	ft_memcpy(proc->reg[0], &id, sizeof(int));
	ft_lst_push_front(g_vm.procs, (void*)proc);
	if (g_vm.vizu)
		vwrite_mem(proc->no, champ->body, (4 - 4 * (*counter) / max) * 1024,
				champ->size);
	(*counter)--;
	return (1);
}

int					put_in_ram(void)
{
	int				counter;

	counter = ft_lst_len(g_vm.champs);
	if (g_vm.vizu)
		ft_printvm();
	ft_lst_iter(g_vm.champs, (void(*)(void*, void*))init_ram_, &counter);
	return (1);
}
