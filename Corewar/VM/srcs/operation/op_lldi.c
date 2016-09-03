/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 13:31:47 by akpenou           #+#    #+#             */
/*   Updated: 2016/07/19 17:26:44 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_lldi(t_proc *proc)
{
	int		n1;
	int		n2;

	if (get_lparam(proc, 0, &n1) && get_lparam(proc, 0, &n2))
	{
		if (0 < proc->PARAM[2] && proc->PARAM[2] < 17)
			store_registre(proc->reg[proc->PARAM[2] - 1],
					get_lindirect(proc, n1 + n2));
		else
			return ;
		if (get_reg((unsigned char *)proc->reg[proc->PARAM[2] - 1]))
			proc->carry = 1;
		else
			proc->carry = 0;
	}
}
