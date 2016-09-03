/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 15:35:59 by akpenou           #+#    #+#             */
/*   Updated: 2016/07/18 17:20:36 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

t_vm	g_vm;

int		main(int ac, char **av)
{
	if (ac < 2)
		ft_putendl_fd("usage: corewar [-v] [-dump n] [[-n id] champion.cor]",
				STDERR_FILENO);
	else
	{
		init_vm();
		parse_all_champs(ac, av);
		ft_execution();
		end_program();
	}
	return (1);
}
