/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 13:31:11 by akpenou           #+#    #+#             */
/*   Updated: 2016/07/19 17:26:09 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_live(t_proc *proc)
{
	t_champ		*champ;

	proc->alive = true;
	if ((champ = get_champ_by_id(proc->params.param[0])))
	{
		champ->live += 1;
		g_vm.last_live = champ->no;
	}
	g_vm.total_live++;
}
