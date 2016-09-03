/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 13:32:49 by akpenou           #+#    #+#             */
/*   Updated: 2016/07/19 17:27:36 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_sub(t_proc *proc)
{
	if (!(0 < proc->PARAM[2] && proc->PARAM[2] < 17))
		return ;
	if (!(0 < proc->PARAM[1] && proc->PARAM[1] < 17))
		return ;
	if (!(0 < proc->PARAM[0] && proc->PARAM[0] < 17))
		return ;
	store_registre(proc->reg[proc->PARAM[2] - 1],
					get_reg((unsigned char *)proc->reg[proc->PARAM[0] - 1]) -
					get_reg((unsigned char *)proc->reg[proc->PARAM[1] - 1]));
	if (!get_reg((unsigned char *)proc->reg[proc->PARAM[2] - 1]))
		proc->carry = 1;
	else
		proc->carry = 0;
}
