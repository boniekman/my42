/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 19:23:39 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/10 20:46:03 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		expose(t_mlx_att *all)
{
	mlx_clear_window(all->mlx, all->win);
	if (all->af && all->af == 'i')
		par(*all, 50, 50);
	else if (all->af && all->af == 'c')
		cavalery(*all, 50, 50);
	else
	{
		all->af = 'i';
		par(*all, 50, 50);
	}
	return (0);
}

static int		choice(int keycode, t_mlx_att *all)
{
	mlx_clear_window(all->mlx, all->win);
	if (keycode == 53)
		end(all->map);
	if (keycode == 126)
		all->map->scale += 5;
	if (keycode == 125)
		all->map->scale -= 5;
	if (keycode == 34 || (keycode != 8 && all->af && all->af == 'i'))
	{
		all->af = 'i';
		par(*all, 50, 50);
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
	if (all.mlx == NULL)
	{
		ft_putendl("MLX connection Error");
		end(all.map);
	}
	all.win = mlx_new_window(all.mlx, x, y, "fdf");
	if (all.win == NULL)
	{
		ft_putendl("Window FAIL");
		end(all.map);
	}
	all.map = map;
	all.map->scale = 1;
	mlx_expose_hook(all.win, expose, &all);
	mlx_key_hook(all.win, choice, &all);
	mlx_loop(all.mlx);
	return (1);
}
