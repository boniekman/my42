/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:39:18 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/16 16:00:26 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define KP 2
#define KPM 1
#define KR 3
#define KRM 2

static int	expose(t_all *all)
{
	mlx_clear_window(all->mlx, all->win);
	put_fract(*all, all->fract);
	mlx_put_image_to_window(all->mlx, all->win, all->i.i, all->offx, all->offy);
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
		(all->zoom)++;
	ft_putnbr(all->iterations);
	put_fract(*all, all->fract);
	mlx_put_image_to_window(all->mlx, all->win, all->i.i, 0, 0);
	return (0);
}

void		main_hook(t_all all)
{
	mlx_expose_hook(all.win, expose, &all);
	mlx_hook(all.win, KP, KPM, choice, &all);
	mlx_loop(all.mlx);
}