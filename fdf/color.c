/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 16:00:07 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/10 21:07:35 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned		count_color(int max_z, int z)
{
	double		c;

	if (z == max_z)
		return (0x0F0F0F0);
	else
	{
		c = (double)z / (double)max_z;
		return (0x0F0F0F0 * c);
	}
}

unsigned		color(t_point a, t_point b)
{
	if (a.z < 0)
		return (0x0000000);
	if (b.color == a.color)
		return (a.color);
	if (b.z < a.z)
		return ((a.color - b.color) / 2);
	return ((b.color - a.color) / 2);
}
