/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 17:01:00 by mbonowic          #+#    #+#             */
/*   Updated: 2016/07/18 17:01:17 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				get_reg(unsigned char registre[REG_SIZE])
{
	unsigned int	n;

	n = ((registre[0] & 0xff) << 24) | ((registre[1] & 0xff) << 16) |
		((registre[2] & 0xff) << 8) | (registre[3] & 0xff);
	return (n);
}

void			store_registre(char registre[REG_SIZE], unsigned int n)
{
	registre[0] = (n >> 24) & 0xff;
	registre[1] = (n >> 16) & 0xff;
	registre[2] = (n >> 8) & 0xff;
	registre[3] = n & 0xff;
}
