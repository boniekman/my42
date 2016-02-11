/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:53:45 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/11 20:08:38 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_i *i, int x, int y, t_color color)
{
	if (x > 0 && x < i->width - 1 && y > 0 && y < i->high - 1)
	{
		i->data[x * i->sline + y * i->bpp / 8] = color.b;
		i->data[x * i->sline + y * i->bpp / 8 + 1] = color.g;
		i->data[x * i->sline + y * i->bpp / 8 + 2] = color.r;
	}
}
