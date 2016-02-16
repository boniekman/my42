/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:37:18 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/16 16:00:19 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		end(char *s)
{
	ft_putendl(s);
	exit(0);
}

void		put_fract(t_all a, unsigned (*f)(int, int, t_all))
{
	int		x;
	int		y;

	x = 0;
	while (x < WDTH - 1)
	{
		y = 0;
		while (y < HIGH - 1)
		{
			put_pixel(&a.i, y, x, f(x, y, a));
			y++;
		}
		x++;
	}
}

t_all		start(t_all all, char *s)
{
	if (ft_strcmp(s, "-J") == 0)
		all.fract = &julia;
	else
		end("./fractol -J -M -B");
	all.iterations = 20;
	all.offy = 0;
	all.offx = 0;
	all.zoom = 1;
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
	return(0);
}
