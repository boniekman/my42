/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 17:01:32 by mbonowic          #+#    #+#             */
/*   Updated: 2016/07/18 16:45:48 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		print_champ__(void *data)
{
	t_champ		*champ;

	champ = (t_champ*)data;
	ft_putnbr(champ->no);
	ft_putstr(" PLAYER: id.");
	ft_putnbr((int)champ->id);
	ft_putstr(" NAME: ");
	ft_putstr(champ->name);
	ft_putstr(" SIZE: ");
	ft_putnbr_endl(champ->size);
}

static void		winner(void)
{
	ft_putstr("\nAND THE WINNER IS:\n PLAYER ");
	ft_putnbr_endl(g_vm.last_live);
}

int				end_program(void)
{
	ft_lst_iter_simple(g_vm.champs, print_champ__);
	winner();
	free_vm();
	return (0);
}
