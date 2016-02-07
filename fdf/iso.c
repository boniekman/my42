/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 17:06:56 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/07 17:33:31 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define X all.map->tab[x][y].x
#define Y all.map->tab[x][y].y
#define Z all.map->tab[x][y].z

void		iso(t_mlx_att all, int offx, int offy)
{
	int		x;
	int		y;
	int		sx;
	int		sy;

	sy = (TERM_W - 2 * offy) / all.map->columns;
	sx = (TERM_H - 2 * offx) / all.map->rows;
	x = 0;
	while (x < all.map->rows)
	{
		y = 0;
		while (y < all.map->columns)
		{
			all.map->tab[x][y].color = count_color(all.map->max_z, Z);
			Y = sy * y + (sx * x + Z) / 2 + offy;
			X = sx * x - Z + offx;
			y++;
		}
		x++;
	}
	put_lines(all);
}
