/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 15:35:05 by akpenou           #+#    #+#             */
/*   Updated: 2016/07/18 15:35:06 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int		ft_speedup(void)
{
	g_vm.vizu->speed += 10;
	ft_player(panel_window(g_vm.vizu->wmain));
	update_panels();
	doupdate();
	return (g_vm.vizu->speed);
}

static int		ft_speeddown(void)
{
	if (g_vm.vizu->speed > 10)
		g_vm.vizu->speed -= 10;
	ft_player(panel_window(g_vm.vizu->wmain));
	update_panels();
	doupdate();
	return (g_vm.vizu->speed);
}

static int		ft_playpause(void)
{
	if (g_vm.vizu->play == TRUE)
		ft_activity(panel_window(g_vm.vizu->wmain), (g_vm.vizu->play = FALSE));
	else
		ft_activity(panel_window(g_vm.vizu->wmain), (g_vm.vizu->play = TRUE));
	update_panels();
	return ((int)(g_vm.vizu->play));
}

int				ft_key(int c)
{
	if (c == 'k')
		ft_speedup();
	else if (c == 'j')
		ft_speeddown();
	else if (c == ' ' || c == 'p')
		ft_playpause();
	else if (c == 's')
		return (c);
	else if (c == 'q')
		ft_endncurses("VM turned off");
	return (c);
}
