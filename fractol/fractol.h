/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 15:38:24 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/16 13:29:59 by mbonowic         ###   ########.fr       */
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

typedef struct	s_img
{
	void		*i;
	char		*data;
	int			bpp;
	int			sline;
	int			e;
}				t_i;

typedef struct	s_all
{
	void		*mlx;
	void		*win;
	t_i			i;
	unsigned	(*fract)(int, int, int);
	int			iterations;
	int			offx;
	int			offy;
	int			zoom;
}				t_all;

t_all			start(t_all all, char *s);
void			end(char *s);
void			put_fract(t_all a, unsigned (*f)(int, int, int));
void			main_hook(t_all all);

void			put_pixel(t_i *i, int x, int y, unsigned c);
unsigned		julia(int x, int y, int max_i);

t_c				c_pow(t_c p);
t_c				c_add(t_c p, t_c c);

#endif
