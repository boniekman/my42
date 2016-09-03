/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 13:31:26 by akpenou           #+#    #+#             */
/*   Updated: 2016/07/19 17:26:22 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_lld(t_proc *proc)
{
	int		n;

	if (get_lparam(proc, 0, &n) && 0 < proc->PARAM[1] && proc->PARAM[1] < 17)
	{
		store_registre(proc->reg[proc->PARAM[1] - 1], n);
		if (!n)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
}
