/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 19:23:39 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/06 20:48:26 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				start_mlx(t_map *map, int x, int y)
{
	t_mlx_att	all;

	all.mlx = mlx_init();
	all.win = mlx_new_window(all.mlx, x, y, "fdf");
	all.map = map;
	cavalery(all, 50, 50);
	return(1);
}
