/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:24:41 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/24 18:05:24 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned	julia(double x, double y, t_all a)
{
	t_c		c;
	t_c		p;
	int		i;

	i = 0;
	c.r = a.m_x;
	c.i = a.m_y;
	p.r = x;
	p.i = y;
	while (i < a.iterations && p.r * p.r + p.i * p.i < 4)
	{
		p = c_pow(p);
		p = c_add(p, c);
		i++;
	}
	return (a.c * i);
}

unsigned	mandelbrot(double x, double y, t_all a)
{
	t_c		c;
	t_c		p;
	int		i;

	i = 0;
	p.r = 0;
	p.i = 0;
	c.r = x;
	c.i = y;
	while (i < a.iterations && p.r * p.r + p.i * p.i < 4)
	{
		p = c_pow(p);
		p = c_add(p, c);
		i++;
	}
	return (a.c * i);
}

unsigned	wtf_ship(double x, double y, t_all a)
{
	t_c		c;
	t_c		p;
	int		i;

	i = 0;
	p.r = 0;
	p.i = 0;
	c.r = x;
	c.i = y;
	while (i < a.iterations && p.r * p.r + p.i * p.i < 4)
	{
		p.r = p.r * p.r - p.i * p.i;
		p.i = 2 * fabs(p.r) * fabs(p.i);
		p = c_add(p, c);
		i++;
	}
	return (a.c * i);
}

unsigned	wtf_ship2(double x, double y, t_all a)
{
	t_c		c;
	t_c		p;
	int		i;

	i = 0;
	p.r = 0;
	p.i = 0;
	c.r = x;
	c.i = y;
	while (i < a.iterations && p.r * p.r + p.i * p.i < 4)
	{
		p.r = p.r * p.r + p.i * p.i;
		p.i = 2 * fabs(p.r) * fabs(p.i);
		p = c_add(p, c);
		i++;
	}
	return (a.c * i);
}
