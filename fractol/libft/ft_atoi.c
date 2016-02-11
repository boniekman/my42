/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:20:10 by mbonowic          #+#    #+#             */
/*   Updated: 2015/11/27 23:25:46 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		conv(char *s)
{
	size_t		i;
	int			n;

	i = 0;
	n = 0;
	while (ft_isdigit((int)s[i]))
	{
		n = n * 10 + (s[i] - '0');
		i++;
	}
	return (n);
}

int				ft_atoi(const char *str)
{
	int			n;
	size_t		i;

	i = 0;
	if (ft_strncmp(str, "-2147483648", 11) == 0)
		return (-2147483648);
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
