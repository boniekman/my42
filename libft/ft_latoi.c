/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_latoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 19:26:04 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/28 19:26:17 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		conv(char *s)
{
	size_t		i;
	long		n;

	i = 0;
	n = 0;
	while (ft_isdigit((int)s[i]))
	{
		n = n * 10 + (s[i] - '0');
		i++;
	}
	return (n);
}

long			ft_latoi(const char *str)
{
	long		n;
	size_t		i;

	i = 0;
	while (!ft_isalnum(str[i]) && str[i] != '+'
			&& str[i] != '-' && ft_isascii(str[i]))
		i++;
	if (str[i] == '-')
	{
		n = conv((char*)&str[i + 1]);
		return (-n);
	}
	if (str[i] == '+')
		n = conv((char*)&str[i + 1]);
	else
		n = conv((char*)&str[i]);
	return (n);
}
