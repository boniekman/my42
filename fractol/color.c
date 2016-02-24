/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:07:02 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/24 18:16:03 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color(int k, t_all *all)
{
	if (k == 18)
		all->c = 0x0000404;
	if (k == 19)
		all->c = 0x0040404;
	if (k == 20)
		all->c = 0x0000004;
}