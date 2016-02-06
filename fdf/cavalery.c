/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cavalery.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 13:32:19 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/06 23:23:39 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "fdf.h"
#define X all.map->tab[x][y].x
#define Y all.map->tab[x][y].y
#define Z all.map->tab[x][y].z

void		cavalery(t_mlx_att all, int offx, int offy)
{
	int		x;
	int		y;

	x = 0;
	while (x < all.map->rows)
	{
		y = 0;
		while (y < all.map->columns)
		{
			Y = 50 * y + Z * (cos(30 * RAD) / tan(45 * RAD)) + offy;
			X = 50 * x + Z * (sin(30 * RAD) / tan(45 * RAD)) + offx;
			y++;
		}
		x++;
	}
	put_lines(all);
}
