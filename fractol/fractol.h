/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 15:38:24 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/11 18:45:11 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>

# define WDTH 500
# define HIGH 500

typedef struct	s_c
{
	double		r;
	double		i;
}				t_c;

typedef struct	s_color
{
	unsigned	r;
	unsigned	g;
	unsigned	b;
}				t_color;

typedef struct	s_img
{
	void		*i;
	char		*data;
	int			bpp;
	int			sline;
	int			e;
	int			width;
	int			high;
}				t_i;

typedef struct	s_all
{
	void		*mlx;
	void		*win;
	t_i			i;
	char		*err;
}				t_all;

void			put_pixel(t_i *i, int x, int y, t_color color);
t_color			julia(int x, int y);

t_c				c_pow(t_c p);
t_c				c_add(t_c p, t_c c);
#endif
