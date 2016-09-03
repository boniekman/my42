/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_home.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 15:34:56 by akpenou           #+#    #+#             */
/*   Updated: 2016/07/18 15:34:57 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

PANEL	*ft_home(int x, int y)
{
	WINDOW	*home;
	char	*s;

	getmaxyx(stdscr, y, x);
	home = ft_makewin(ft_makecoord(50, 20), ft_makecoord((x - 25) / 2,
				(y - 25) / 2), TRUE);
	s = ft_strdup("WELCOME ON THE COREWAR VIRTUAL MACHINE");
	mvwprintw(home, 5, (50 - ft_strlen(s)) / 2, "%s", s);
	free(s);
	s = ft_strdup(" There are actually %d players in the arena");
	mvwprintw(home, 10, (50 - ft_strlen(s)) / 2, "%s", s);
	free(s);
	s = ft_strdup("----- PLEASE PRESS SPACE TO CONTINUE -----");
	mvwprintw(home, 15, (50 - ft_strlen(s)) / 2, "%s", s);
	free(s);
	return (new_panel(home));
}

void	ft_exitmenu(void)
{
	char c;

	while ((c = getch()) != 27)
	{
		if (c == 'q')
			ft_endncurses("VM turned off");
		if (c == ' ')
			break ;
	}
}

void	vwrite_mem(int color, void *memoire, size_t index, size_t len)
{
	unsigned char	*mem;
	size_t			i;
	unsigned int	pos;

	i = -1;
	mem = memoire;
	wattron(panel_window(g_vm.vizu->memory), COLOR_PAIR(color));
	while (++i < len)
	{
		pos = (i + index) % MEM_SIZE;
		mvwprintw(panel_window(g_vm.vizu->memory), 1 + pos / 64,
										2 + pos % 64 * 3, "%02.2hhx", mem[i]);
	}
	update_panels();
	doupdate();
	wattroff(panel_window(g_vm.vizu->memory), COLOR_PAIR(color));
}

WINDOW	*ft_memory(WINDOW *memory)
{
	int		i;

	i = -1;
	while (++i < MEM_SIZE)
		mvwprintw(memory, 1 + i / 64, 2 + i % 64 * 3, "%02.2hhx", g_vm.ram[i]);
	return (memory);
}
