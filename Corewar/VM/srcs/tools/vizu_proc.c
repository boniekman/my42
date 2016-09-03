/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizu_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 16:44:38 by mbonowic          #+#    #+#             */
/*   Updated: 2016/07/19 17:30:22 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_proc(t_proc *prc, bool aff)
{
	int		pos;

	return ;
	if (!g_vm.vizu)
		return ;
	pos = prc->pc + prc->start;
	if (aff)
		vwrite_mem(prc->no + 4, &(g_vm.ram[pos]), pos, 1);
	else
		vwrite_mem(prc->no, &(g_vm.ram[pos]), pos, 1);
}
