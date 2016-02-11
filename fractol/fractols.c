/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:24:41 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/11 20:35:29 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_c			c_pow(t_c p)
{
	t_c		r;

	r.r = p.r * p.r - p.i * p.i;
	r.i = 2.0 * p.r * p.i;
	return (r);
}

t_c			c_add(t_c p, t_c c)
{
	t_c		r;

	r.r = p.r + c.r;
	r.i = p.i + c.i;
	return (r);
}

t_color		julia(int x, int y)
{
	t_color	color;
	t_c		c;
	t_c		p;
	int		i;

	i = 0;
	c.r = -1;
	c.i = 0.1;
	p.r = ((double)x - WDTH / 2) / ((double)WDTH / 4);
	p.i = -((double)y - HIGH / 2) / ((double)HIGH / 4);
	while (i < 20 && p.r * p.r + p.i * p.i < 4)
	{
		p = c_pow(p);
		p = c_add(p, c);
		i++;
	}
	if (i == 20)
	{
		color.r = 0;
		color.g = 0;
		color.b = 255;
	}
	else if (p.i > 0)
	{
		color.r = 255;
		color.g = 255;
		color.b = 255;
	}
	else
	{
		color.r = 255;
		color.g = 255;
		color.b = 255;
	}
	return (color);
}
