/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 13:26:09 by akpenou           #+#    #+#             */
/*   Updated: 2016/07/19 17:25:56 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_add(t_proc *proc)
{
	if (0 < proc->PARAM[2] && proc->PARAM[2] < 17
			&& 0 < proc->PARAM[1] && proc->PARAM[1] < 17
			&& 0 < proc->PARAM[0] && proc->PARAM[0] < 17)
	{
		store_registre(proc->reg[proc->PARAM[2] - 1],
				get_reg((unsigned char *)proc->reg[proc->PARAM[0] - 1]) +
				get_reg((unsigned char *)proc->reg[proc->PARAM[1] - 1]));
		if (!get_reg((unsigned char *)proc->reg[proc->PARAM[2] - 1]))
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	return ;
}
