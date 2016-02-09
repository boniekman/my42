/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 19:23:39 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/09 16:16:03 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
int				expose(t_mlx_att *all)
{
	mlx_clear_window(all->mlx, all->win);
	if (all->af && all->af == 'i')
		iso(*all, 50, 50);
	else if (all->af && all->af == 'c')
		cavalery(*all, 50, 50);
	else
	{
		all->af = 'i';
		iso(*all, 50, 50);
	}
	return (0);
}

int				choice(int keycode, t_mlx_att *all)
{
	mlx_clear_window(all->mlx, all->win);
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
		all->map->scale += 5;
	if (keycode == 125)
		all->map->scale -= 5;
	if (keycode == 34 || (keycode != 8 && all->af && all->af == 'i'))
	{
		all->af = 'i';
		iso(*all, 50, 50);
	}
	else if (keycode == 8 || (keycode != 34 && all->af && all->af == 'c'))
	{
		all->af = 'c';
		cavalery(*all, 50, 50);
	}
	return (0);
}

int				start_mlx(t_map *map, int x, int y)
{
	t_mlx_att	all;

	all.mlx = mlx_init();
	all.win = mlx_new_window(all.mlx, x, y, "fdf");
	all.map = map;
	all.map->scale = 1;
	mlx_expose_hook(all.win, expose, &all);
	mlx_key_hook(all.win, choice, &all);
	mlx_loop(all.mlx);
	return (1);
}
