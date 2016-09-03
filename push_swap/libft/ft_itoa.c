/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:47:25 by mbonowic          #+#    #+#             */
/*   Updated: 2015/11/27 23:30:21 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*make_nb(int n, int i, int dec, int sign)
{
	char	*nbr;

	nbr = (char*)malloc(sizeof(char) * (i + 1));
	if (nbr == NULL)
		return (NULL);
	i = 0;
	if (sign)
	{
		nbr[i] = '-';
		i++;
	}
	while (dec > 0)
	{
		nbr[i] = (n / dec) + '0';
		n %= dec;
		dec /= 10;
		i++;
	}
	nbr[i] = '\0';
	return (nbr);
}

char		*ft_itoa(int n)
{
	int		i;
	int		dec;
	int		sign;

	i = 1;
	dec = 1;
	sign = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return ("-2147483648");
		n *= -1;
		i++;
		sign = 1;
	}
	while (dec * 10 <= n)
	{
		dec *= 10;
		i++;
	}
	return (make_nb(n, i, dec, sign));
}
