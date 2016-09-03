/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc_vm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 15:28:14 by akpenou           #+#    #+#             */
/*   Updated: 2016/07/18 15:28:16 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void	del_proc__(t_proc *proc)
{
	free(proc);
}

static void	del_champ__(t_champ *champ)
{
	if (champ->body)
		ft_strdel(&champ->body);
	if (champ->name)
		ft_strdel(&champ->name);
	free(champ);
}

int			init_vm(void)
{
	ft_memset(&g_vm, 0, sizeof(t_vm));
	ft_memset(g_vm.ram, 0, MEM_SIZE);
	g_vm.vizu = NULL;
	g_vm.champs = ft_lst_new();
	g_vm.procs = ft_lst_new();
	g_vm.dump = -2;
	g_vm.actual_cycle = 0;
	g_vm.cycle_to_die = CYCLE_TO_DIE;
	g_vm.cycle_to_check = CYCLE_TO_DIE;
	return (1);
}

void		free_vm(void)
{
	if (g_vm.vizu)
		free(g_vm.vizu);
	ft_lst_del(g_vm.champs, (void(*)(void*))del_champ__);
	ft_lst_del(g_vm.procs, (void(*)(void*))del_proc__);
}

void		fatal_exit_vm(char *message)
{
	ft_putstr_fd("corewar: ", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	if (g_vm.vizu)
		ft_putendl_fd("Quit vizualizer", STDERR_FILENO);
	free_vm();
	exit(1);
}
