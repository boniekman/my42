/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:37:18 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/11 20:10:55 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			main(void)
{
	t_all	all;
	t_color	c;
	int		x;
	int		y;

	x = 0;
	c.r = 255;
	c.g = 0;
	c.b = 0;
	all.mlx = mlx_init();
	all.win = mlx_new_window(all.mlx, WDTH, HIGH, "fractol");
	all.i.i = mlx_new_image(all.mlx, WDTH, HIGH);
	all.i.width = WDTH;
	all.i.high = HIGH;
	all.i.data = mlx_get_data_addr(all.i.i, &all.i.bpp, &all.i.sline, &all.i.e);
	while (x < WDTH - 1)
	{
		y = 0;
		while (y < HIGH - 1)
		{
			put_pixel(&all.i, y, x, julia(x, y));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(all.mlx, all.win, all.i.i, 0, 0);
	mlx_loop(all.mlx);
	return(0);
}
