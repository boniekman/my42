/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:36:01 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 11:36:02 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		count_significant_bit(int value)
{
	int bit;

	bit = 31;
	while (bit >= 0)
	{
		if (value & (1 << bit))
			return (bit + 1);
		bit--;
	}
	return (0);
}

int		count_nb_octet(wchar_t letter)
{
	int nb_bit;

	nb_bit = count_significant_bit(letter);
	if (nb_bit <= 7)
		return (1);
	else if (nb_bit <= 11)
		return (2);
	else if (nb_bit <= 16)
		return (3);
	else
		return (4);
}
