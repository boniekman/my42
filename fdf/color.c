/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 16:00:07 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/07 17:33:37 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned		count_color(int max_z, int z)
{
	double		c;

	if (z == max_z)
		return (0x0FFFFFF);
	c = (double)z / (double)max_z;
	if (c == 0)
		return (0x0404040);
	if (c < 0.25)
		return (0x0080808);
	if (c < 0.5)
		return (0x00F0F0F);
	else
		return (0x08F8F8F);
}

unsigned		color(t_point a, t_point b)
{
	unsigned	r;

	r = (b.color - a.color) / 2;
	return (a.color + r);
}
