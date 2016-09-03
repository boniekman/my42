/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_bit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 15:33:40 by akpenou           #+#    #+#             */
/*   Updated: 2016/07/18 15:33:42 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

unsigned int		reverse_int(unsigned int number)
{
	unsigned int	num;
	unsigned char	tmp;

	num = 0;
	tmp = ((number << 24) >> 24);
	num |= (tmp << 24);
	tmp = (((number >> 8) << 24) >> 24);
	num |= (tmp << 16);
	tmp = (((number >> 16) << 24) >> 24);
	num |= (tmp << 8);
	tmp = (((number >> 24) << 24) >> 24);
	num |= tmp;
	return (num);
}

unsigned short		reverse_short(unsigned short number)
{
	unsigned short	num;
	char			tmp;

	num = 0;
	tmp = number & 0xff;
	num |= (tmp << 8);
	tmp = (number & 0xff00) >> 8;
	num |= tmp;
	return (num);
}
