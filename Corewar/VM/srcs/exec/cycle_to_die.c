/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_to_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 15:35:31 by akpenou           #+#    #+#             */
/*   Updated: 2016/07/19 18:31:25 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		reset_live__(void *data)
{
	t_champ	*champ;

	champ = data;
	champ->live = 0;
}

static void		ft_check_decrementation(int *last_decrementation)
{
	if (g_vm.total_live >= NBR_LIVE || *last_decrementation >= MAX_CHECKS)
	{
		g_vm.cycle_to_die -= CYCLE_DELTA;
		last_decrementation = 0;
	}
	else
		*last_decrementation += 1;
}

bool			ft_kill_processus(void *prc, void *useless)
{
	t_champ		*champ;

	(void)useless;
	if (((t_proc *)prc)->alive)
		return ((((t_proc *)prc)->alive = FALSE));
	if ((champ = get_champ_by_no(((t_proc *)prc)->no)))
		champ->proc -= 1;
	return (TRUE);
}

int				ft_cycle_to_die(void)
{
	static int last_decrementation = 0;

	ft_check_decrementation(&last_decrementation);
	ft_lst_remove(g_vm.procs, &ft_kill_processus, NULL, free);
	ft_lst_iter_simple(g_vm.procs, reset_live__);
	g_vm.total_live = 0;
	g_vm.cycle_to_check = g_vm.cycle_to_die + g_vm.actual_cycle;
	return (ft_lst_len(g_vm.procs) ? TRUE : FALSE);
}
