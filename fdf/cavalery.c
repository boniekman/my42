/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cavalery.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 13:32:19 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/04 14:01:20 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	calculate(t_map *map, int offx, int offy, char o)
{
	//petla jak ta na dole z dodatkowa funkcja obliczajace x i y dla struktury point
	//i tyle powinno wystarczyc :)
	//Juz i tak niezle ogarnales strukture danych itd :)
}

void		cavalery(t_mlx_att all, int offx, int offy)
{
	int			x;
	int			y;

	calculate(all->map, offx, offy);
	x = 0;
	while (x < all.map->rows)
	{
		y = 0;
		while (y < all.map->columns)
		{
			mlx_pixel_put(all.mlx, all.win, 30 * y + offy, 30 * x + offx, 0x00099FF);
			if (all.map->tab[x][y] > 0)
			{
				mlx_pixel_put(all.mlx, all.win, all.map->tab[x][y].y, all.map->tab[x][y].x, 0x0FFFFF);
				mlx_pixel_put(all.mlx, all.win, 30 * y + all.map->tab[x][y] * (sin(30 * RAD) / tan(45 * RAD)) + offy, 30 * x + all.map->tab[x][y] * (cos(30 * RAD) / tan(45 * RAD)) + offx, 0x0FFFFFF);
			}
			y++;
		}
		x++;
	}
	mlx_loop(all.mlx);
}
