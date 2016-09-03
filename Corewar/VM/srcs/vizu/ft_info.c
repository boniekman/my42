/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 15:34:59 by akpenou           #+#    #+#             */
/*   Updated: 2016/07/18 15:35:01 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void			ft_activity(WINDOW *wmain, char activity)
{
	mvwprintw(wmain, 2, (80 - 19) / 2, "+-----------------+");
	mvwprintw(wmain, 2 + 1, (80 - 19) / 2, "|                 |");
	mvwprintw(wmain, 2 + 2, (80 - 19) / 2, "+-----------------+");
	if (activity == TRUE)
		mvwprintw(wmain, 2 + 1, (80 - 19) / 2 + 6, "RUNNING");
	else
		mvwprintw(wmain, 2 + 1, (80 - 19) / 2 + 6, " PAUSE ");
}

void			ft_player(WINDOW *wmain)
{
	t_lst_elem__	*lstchamp;
	t_champ			*champ;
	int				i;

	i = 6;
	lstchamp = g_vm.champs->head;
	mvwprintw(wmain, i, 3, "COLOR\tNAME\t\tNB_PROC\tNB_LIVE");
	while (lstchamp && ++i)
	{
		champ = lstchamp->data;
		mvwprintw(wmain, i, 3, "%-9s\t%-9s\t%7d\t%7d", g_vm.vizu->color[i - 7],
				champ->name, champ->proc, champ->live);
		lstchamp = lstchamp->next;
	}
	mvwprintw(wmain, (i += 3), 3, "NUMBER OF CYCLE\t: %-5d", g_vm.actual_cycle);
	mvwprintw(wmain, ++i, 3, "CYCLE TO CHECK\t: %-5d", g_vm.cycle_to_check);
	mvwprintw(wmain, ++i, 3, "TOTAL LIVE\t\t: %-5d", g_vm.total_live);
	mvwprintw(wmain, ++i, 3, "CYCLE TO DIE\t\t: %-5d", g_vm.cycle_to_die);
	mvwprintw(wmain, ++i, 3, "MAX CHECK\t\t: %-5d", MAX_CHECKS);
	mvwprintw(wmain, (i += 2), 3, "SPEED\t\t\t: %-5d CYCLE/SEC",
														g_vm.vizu->speed);
}

static void		ft_help(WINDOW *wmain, int x, int y)
{
	int		i;

	y = y - 7;
	i = 0;
	while (++i < x)
		mvwprintw(wmain, y, i, "-");
	mvwprintw(wmain, y, 0, "+");
	mvwprintw(wmain, y, x, "+");
	mvwprintw(wmain, y, (x - 12) / 2, "    HELP    ");
	mvwprintw(wmain, (y += 2), 3, "j\tOR k\t\t\tDECREASE OR INCREASE SPEED");
	mvwprintw(wmain, ++y, 3, "P\tOR SPACEBAR\tPAUSE OR RESUME");
	mvwprintw(wmain, ++y, 3, "Q\tOR ESC\t\tQUIT");
}

void			ft_printvm(void)
{
	g_vm.vizu->memory = new_panel(ft_makewin(ft_makecoord(193, 64),
													ft_makecoord(0, 0), TRUE));
	g_vm.vizu->wmain = new_panel(ft_makewin(ft_makecoord(80, 28),
												ft_makecoord(194, 0), TRUE));
	ft_memory(panel_window(g_vm.vizu->memory));
	ft_activity(panel_window(g_vm.vizu->wmain), g_vm.vizu->play);
	ft_player(panel_window(g_vm.vizu->wmain));
	ft_help(panel_window(g_vm.vizu->wmain), 0, 100);
	update_panels();
	doupdate();
}
