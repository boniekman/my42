/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 14:45:18 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/10 15:37:06 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_input(t_map map)
{
	int		x;
	int		y;

	x = 0;
	while (x < map.rows)
	{
		y = 0;
		while (y < map.columns)
		{
			ft_putnbr(map.tab[x][y].z);
			ft_putstr("  ");
			y++;
		}
		ft_putendl("");
		x++;
	}
}

static int	er_msg(t_map *map)
{
	ft_putendl("Argument Error");
	end(map);
	return (0);
}

static void	map_init(t_map *map)
{
	map->tab = NULL;
	map->rows = 0;
	map->columns = 0;
}

int			main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (er_msg(0));
	map_init(&map);
	if (set_map(&map, argv[1]) == -1)
		return (er_msg(&map));
	print_input(map);
	start_mlx(&map, TERM_W, TERM_H);
	return (0);
}
