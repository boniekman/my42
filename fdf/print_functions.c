/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 19:23:57 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/10 16:23:07 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		point_swap(t_point *p1, t_point *p2)
{
	double		tmp;

	tmp = p2->x;
	p2->x = p1->x;
	p1->x = tmp;
	tmp = p2->y;
	p2->y = p1->y;
	p1->y = tmp;
	tmp = p2->z;
	p2->z = p1->z;
	p1->z = tmp;
}

static void		put_vertical(t_mlx_att l, t_point p1, t_point p2)
{
	double		a;
	double		b;

	if (p2.x < p1.x)
		point_swap(&p2, &p1);
	a = (p2.y - p1.y) / (p2.x - p1.x);
	b = p1.y - a * p1.x;
	while (p1.x <= p2.x)
	{
		mlx_pixel_put(l.mlx, l.win, p1.x * a + b, p1.x, color(p1, p2));
		p1.x += 0.01;
	}
}

static void		put_horizontal(t_mlx_att l, t_point p1, t_point p2)
{
	double		a;
	double		b;

	if (p2.x != p1.x)
	{
		if (p2.x < p1.x)
			point_swap(&p2, &p1);
		a = (p2.y - p1.y) / (p2.x - p1.x);
		b = p1.y - a * p1.x;
		while (p1.x <= p2.x)
		{
			mlx_pixel_put(l.mlx, l.win, p1.x * a + b, p1.x, color(p1, p2));
			p1.x += 0.01;
		}
	}
	else
		while (p1.y <= p2.y)
		{
			mlx_pixel_put(l.mlx, l.win, p1.y, p1.x, color(p1, p2));
			p1.y += 0.01;
		}
}

void			put_lines(t_mlx_att all)
{
	int			x;
	int			y;

	x = 0;
	while (x < all.map->rows)
	{
		y = 0;
		while (y < all.map->columns)
		{
			if (x != all.map->rows - 1)
				put_vertical(all, all.map->tab[x][y], all.map->tab[x + 1][y]);
			if (y != all.map->columns - 1)
				put_horizontal(all, all.map->tab[x][y], all.map->tab[x][y + 1]);
			y++;
		}
		x++;
	}
}
