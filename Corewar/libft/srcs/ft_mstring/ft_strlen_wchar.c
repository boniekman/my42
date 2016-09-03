/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_wchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:29:57 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:58:41 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mstring.h>

int		strlen_wchar(wchar_t *str)
{
	int i;
	int length;
	int nb_bit;

	i = 0;
	length = 0;
	while (str[i])
	{
		nb_bit = count_significant_bit(str[i]);
		if (nb_bit <= 7)
			length += 1;
		else if (nb_bit <= 11)
			length += 2;
		else if (nb_bit <= 16)
			length += 3;
		else
			length += 4;
		i++;
	}
	return (length);
}
