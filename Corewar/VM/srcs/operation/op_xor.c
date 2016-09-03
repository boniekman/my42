/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 13:35:17 by akpenou           #+#    #+#             */
/*   Updated: 2016/07/19 17:27:52 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			op_xor(t_proc *proc)
{
	int		n1;
	int		n2;

	if (get_param(proc, 0, &n1) && get_param(proc, 1, &n2))
	{
		if (0 < proc->PARAM[2] && proc->PARAM[2] < 17)
			store_registre(proc->reg[proc->PARAM[2] - 1], n2 ^ n2);
		else
			return ;
		if (!get_reg((unsigned char *)proc->reg[proc->PARAM[2] - 1]))
			proc->carry = 1;
		else
			proc->carry = 0;
	}
}
