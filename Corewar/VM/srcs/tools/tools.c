/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 15:28:08 by akpenou           #+#    #+#             */
/*   Updated: 2016/07/18 17:01:36 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				get_indirect(t_proc *prc, int pos)
{
	int		n;

	n = 0;
	n += (g_vm.ram[(prc->pc + (pos % IDX_MOD)) % MEM_SIZE] & 0xff) << 24;
	n += (g_vm.ram[(prc->pc + ((pos + 1) % IDX_MOD)) % MEM_SIZE] & 0xff) << 16;
	n += (g_vm.ram[(prc->pc + ((pos + 2) % IDX_MOD)) % MEM_SIZE] & 0xff) << 8;
	n += g_vm.ram[(prc->pc + ((pos + 3) % IDX_MOD)) % MEM_SIZE] & 0xff;
	return (n);
}

int				get_lindirect(t_proc *prc, int pos)
{
	int		n;

	n = 0;
	n += (g_vm.ram[(prc->pc + pos) % MEM_SIZE] & 0xff) << 24;
	n += (g_vm.ram[(prc->pc + (pos + 1)) % MEM_SIZE] & 0xff) << 16;
	n += (g_vm.ram[(prc->pc + (pos + 2)) % MEM_SIZE] & 0xff) << 8;
	n += g_vm.ram[(prc->pc + (pos + 3)) % MEM_SIZE] & 0xff;
	return (n);
}

int				get_direct(t_proc *prc, int pos)
{
	return (prc->PARAM[pos]);
}

unsigned int	get_param(t_proc *prc, int n, int *res)
{
	if (prc->MODE[n] == M_IND)
		*res = get_indirect(prc, prc->PARAM[n]);
	else if (prc->MODE[n] == M_REG && (unsigned int)prc->PARAM[n] <= 16)
		*res = get_reg((unsigned char*)(prc->reg[prc->PARAM[n] - 1]));
	else if (prc->MODE[n] == M_D2)
		*res = get_direct(prc, n);
	else
		return (0);
	return (1);
}

unsigned int	get_lparam(t_proc *prc, int n, int *res)
{
	if (prc->MODE[n] == M_IND)
		*res = get_lindirect(prc, prc->PARAM[n]);
	else if (prc->MODE[n] == M_REG && (unsigned int)prc->PARAM[n] <= 16)
		*res = get_reg((unsigned char*)(prc->reg[prc->PARAM[n] - 1]));
	else if (prc->MODE[n] == M_D2)
		*res = get_direct(prc, n);
	else
		return (0);
	return (1);
}
