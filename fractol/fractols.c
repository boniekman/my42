/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:24:41 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/17 10:46:48 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned	julia(int x, int y, t_all a)
{
	t_c		c;
	t_c		p;
	int		i;

	i = 0;
	c.r = a.m_x;
	c.i = a.m_y;
	p.r = ((double)x + a.offx - (double)WDTH / 2) / ((double)WDTH / 4) / a.zoom;
	p.i = ((double)y + a.offy - (double)HIGH / 2) / ((double)HIGH / 4) / a.zoom;
	while (i < a.iterations && p.r * p.r + p.i * p.i < 4)
	{
		p = c_pow(p);
		p = c_add(p, c);
		i++;
	}
	return (0x03 * i);
}
