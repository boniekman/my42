/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 15:29:40 by akpenou           #+#    #+#             */
/*   Updated: 2016/07/18 17:18:06 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		g_tab[16][4] = {{MODE_DIR, 0, 0, 0}, {MODE_DIR | MODE_IND,
		MODE_REG, 0, 0}, {MODE_REG, MODE_IND | MODE_REG, 0, 0}, {MODE_REG,
		MODE_REG, MODE_REG, 0}, {MODE_REG, MODE_REG, MODE_REG, 0}, {MODE_REG |
		MODE_DIR | MODE_IND, MODE_REG | MODE_IND | MODE_DIR, MODE_REG, 0},
	{MODE_REG | MODE_IND | MODE_DIR, MODE_REG | MODE_IND | MODE_DIR,
		MODE_REG, 0}, {MODE_REG | MODE_IND | MODE_DIR, MODE_REG | MODE_IND |
		MODE_DIR, MODE_REG, 0}, {MODE_DIR, 0, 0, 0}, {MODE_REG | MODE_DIR |
		MODE_IND, MODE_DIR | MODE_REG, MODE_REG, 0}, {MODE_REG, MODE_REG |
		MODE_DIR | MODE_IND, MODE_DIR | MODE_REG, 0}, {MODE_DIR, 0, 0, 0},
	{MODE_DIR | MODE_IND, MODE_REG, 0, 0}, {MODE_REG | MODE_DIR | MODE_IND,
		MODE_DIR | MODE_REG, MODE_REG, 0}, {MODE_DIR, 0, 0, 0}, {MODE_REG, 0, 0,
		0}};

static int		check_param(int p_mode, int mode, int param)
{
	if (p_mode == M_D2 && (MODE_DIR & mode))
		return (1);
	if (p_mode == M_REG && (MODE_REG & mode) && param > 0 && param <= 16)
		return (1);
	if (p_mode == M_IND && (MODE_IND & mode))
		return (1);
	return (0);
}

int				check_params(t_proc *prc)
{
	int			no_param;
	int			*mode;

	no_param = -1;
	if (prc->params.opcode < 1 || prc->params.opcode > 16)
		return (0);
	mode = g_tab[prc->params.opcode - 1];
	while (mode[++no_param])
		if (!check_param(prc->MODE[no_param], mode[no_param],
					prc->params.param[no_param]))
			return (0);
	return (1);
}
