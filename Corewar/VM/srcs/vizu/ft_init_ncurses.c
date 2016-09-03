/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ncurses.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 15:35:02 by akpenou           #+#    #+#             */
/*   Updated: 2016/07/18 15:35:03 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void			ft_endncurses(char *s)
{
	endwin();
	fatal_exit_vm(s);
}

t_coord			ft_makecoord(int x, int y)
{
	t_coord		coord;

	coord.x = x;
	coord.y = y;
	return (coord);
}

WINDOW			*ft_makewin(t_coord dim, t_coord coord, int putborder)
{
	WINDOW		*scr;

	scr = newwin(dim.y + 2, dim.x + 2, coord.y, coord.x);
	if (putborder)
		wborder(scr, '|', '|', '-', '-', '+', '+', '+', '+');
	return (scr);
}

static void		ft_initcolor(void)
{
	start_color();
	init_color(BLUE, 0 / 255 * 1000, 102 / 255 * 1000, 1000);
	init_color(GREEN, 0, 255 / 255 * 1000, 0);
	init_color(RED, 255 / 255 * 1000, 0, 0);
	init_color(YELLOW, 255 / 255 * 1000, 255 / 255 * 1000, 0);
	init_color(GREY, 300, 300, 300);
	init_color(WHITE, 0, 0, 0);
	init_pair(P1, GREEN, COLOR_BLACK);
	init_pair(P2, YELLOW, COLOR_BLACK);
	init_pair(P3, RED, COLOR_BLACK);
	init_pair(P4, BLUE, COLOR_BLACK);
	init_pair(PC1, GREEN, GREY);
	init_pair(PC2, YELLOW, GREY);
	init_pair(PC3, RED, GREY);
	init_pair(PC4, BLUE, GREY);
	g_vm.vizu->color[0] = "GREEN";
	g_vm.vizu->color[1] = "YELLOW";
	g_vm.vizu->color[2] = "RED";
	g_vm.vizu->color[3] = "BLUE";
}

int				ft_initncurses(void)
{
	PANEL * home;
	initscr();
	if (!(g_vm.vizu = (t_vizu *)ft_memalloc(sizeof(t_vizu))))
		ft_endncurses("critical error -> malloc failed");
	g_vm.vizu->speed = 1;
	ft_initcolor();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	home = ft_home(0, 0);
	show_panel(home);
	update_panels();
	doupdate();
	ft_exitmenu();
	del_panel(home);
	return (1);
}
