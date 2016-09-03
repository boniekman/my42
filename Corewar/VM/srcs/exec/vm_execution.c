/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 15:35:34 by akpenou           #+#    #+#             */
/*   Updated: 2016/07/19 17:59:46 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		vizualizer_execution(void)
{
	int		c;

	c = 0;
	while (g_vm.vizu && g_vm.vizu->play == FALSE && (char)c != 's')
		ft_key((c = getch()));
	ft_player(panel_window(g_vm.vizu->wmain));
	ft_key(getch());
	usleep(1000000 / g_vm.vizu->speed);
	update_panels();
	doupdate();
}

static void	ft_lst_iter_controller(t_lst *lst, void (*f)(void *data))
{
	t_lst_elem__ *elem;

	elem = lst->head;
	while (elem)
	{
		f(elem->data);
		elem = elem->next;
	}
}

void		ft_execution(void)
{
	while (++g_vm.actual_cycle >= 0 && g_vm.cycle_to_die > 0)
	{
		ft_lst_iter_controller(g_vm.procs, (void(*)(void*))op_controller);
		if (g_vm.vizu)
			vizualizer_execution();
		if (g_vm.actual_cycle == g_vm.cycle_to_check && !ft_cycle_to_die())
			break ;
		if (!--g_vm.dump)
			break ;
	}
	if (g_vm.vizu)
		vizualizer_execution();
	if (!g_vm.dump)
		dump_mem();
}
