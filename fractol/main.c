/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:37:18 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/24 18:17:34 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		end(char *s)
{
	ft_putendl(s);
	exit(0);
}

void		put_fract(t_all a, unsigned (*f)(double, double, t_all))
{
	int		x;
	int		y;

	x = 0;
	while (x < WDTH - 1)
	{
		y = 0;
		while (y < HIGH - 1)
		{
			put_pixel(&a.i, y, x, f(((double)x + a.offx - (double)WDTH / 2)
						/ ((double)WDTH / 4) / a.zoom,
						((double)y + a.offy - (double)HIGH / 2)
						/ ((double)HIGH / 4) / a.zoom, a));
			y++;
		}
		x++;
	}
}

t_all		start(t_all all, char *s)
{
	if (ft_strcmp(s, "-J") == 0)
		all.fract = &julia;
	else if (ft_strcmp(s, "-M") == 0)
		all.fract = &mandelbrot;
	else if (ft_strcmp(s, "-W") == 0)
		all.fract = &wtf_ship;
	else if (ft_strcmp(s, "-W2") == 0)
		all.fract = &wtf_ship2;
	else
		end("./fractol -J -M -W -W2");
	all.iterations = 50;
	all.offy = 0;
	all.offx = 0;
	all.zoom = 1;
	all.m_x = 0;
	all.m_y = 0;
	all.c = 4;
	all.motion_block = 1;
	all.mlx = mlx_init();
	all.win = mlx_new_window(all.mlx, WDTH, HIGH, "fractol");
	all.i.i = mlx_new_image(all.mlx, WDTH, HIGH);
	all.i.data = mlx_get_data_addr(all.i.i, &all.i.bpp, &all.i.sline, &all.i.e);
	return (all);
}

int			main(int argc, char **argv)
{
	t_all	all;

	if (argc != 2)
		end("./fractol -J -M -B");
	all = start(all, argv[1]);
	main_hook(all);
	return (0);
}
