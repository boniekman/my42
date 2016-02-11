/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 20:24:29 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/10 20:24:38 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define X all.map->tab[x][y].x
#define Y all.map->tab[x][y].y
#define Z all.map->tab[x][y].z

void		par(t_mlx_att all, int offx, int offy)
{
	int		x;
	int		y;
	double	sx;
	double	sy;

	sx = (TERM_H) / (all.map->rows + all.map->columns / 2);
	sy = (TERM_W) / (all.map->columns + all.map->rows / 2);
	x = 0;
	while (x < all.map->rows)
	{
		y = 0;
		while (y < all.map->columns)
		{
			all.map->tab[x][y].color = count_color(all.map->max_z, Z);
			Y = sy * y + (sx * x + all.map->scale * Z) / 2 + offy;
			X = sx * x - all.map->scale * Z + offx;
			y++;
		}
		x++;
	}
	put_lines(all);
}
