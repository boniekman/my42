/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:39:18 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/24 18:17:47 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define KP 2
#define KPM (1L<<0)

#define KMCL 1
#define KMCR 2
#define KMU 5
#define KMD 4
#define KML 7
#define KMR 6

#define MOTNOT 6
#define MOTNOTM (1L<<6)

static int	expose(t_all *all)
{
	mlx_clear_window(all->mlx, all->win);
	put_fract(*all, all->fract);
	mlx_put_image_to_window(all->mlx, all->win, all->i.i, all->offx, all->offy);
	return (0);
}

static int	motion(int x, int y, t_all *all)
{
	if (all->motion_block == -1)
		return (0);
	all->m_x = (double)x / (double)WDTH * 4 - 2;
	all->m_y = (double)y / (double)HIGH * 4 - 2;
	mlx_clear_window(all->mlx, all->win);
	put_fract(*all, all->fract);
	mlx_put_image_to_window(all->mlx, all->win, all->i.i, 0, 0);
	return (0);
}

static int	choice(int keycode, t_all *all)
{
	mlx_clear_window(all->mlx, all->win);
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
		all->offy -= 10;
	if (keycode == 125)
		all->offy += 10;
	if (keycode == 124)
		all->offx += 10;
	if (keycode == 123)
		all->offx -= 10;
	if (keycode == 69)
		(all->iterations)++;
	if (keycode == 78)
		(all->iterations)--;
	if (keycode == 49)
		all->motion_block *= -1;
	if (keycode == 18 || keycode == 19 || keycode == 20)
		color(keycode, all);
	put_fract(*all, all->fract);
	mlx_put_image_to_window(all->mlx, all->win, all->i.i, 0, 0);
	return (0);
}

static int	roll(int keycode, int x, int y, t_all *all)
{
	if (keycode == KMU || keycode == KMCL)
	{
		all->zoom *= 1.1;
		all->offx = all->offx * 1.1;
		all->offy = all->offy * 1.1;
		all->iterations += 2;
	}
	if (keycode == KMD || keycode == KMCR)
	{
		all->zoom /= 1.1;
		all->offx /= 1.1;
		all->offy /= 1.1;
		all->iterations -= 2;
	}
	x = y;
	mlx_clear_window(all->mlx, all->win);
	put_fract(*all, all->fract);
	mlx_put_image_to_window(all->mlx, all->win, all->i.i, 0, 0);
	return (0);
}

void		main_hook(t_all all)
{
	mlx_expose_hook(all.win, expose, &all);
	mlx_hook(all.win, KP, KPM, choice, &all);
	mlx_hook(all.win, MOTNOT, MOTNOTM, motion, &all);
	mlx_mouse_hook(all.win, roll, &all);
	mlx_loop(all.mlx);
}
