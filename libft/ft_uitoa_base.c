/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 22:20:39 by mbonowic          #+#    #+#             */
/*   Updated: 2016/05/18 11:19:30 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		g_base[] = "0123456789ABCDEF";

static int		get_length(unsigned long long int value, int base)
{
	int count;

	count = 0;
	if (value == 0)
		count = 1;
	while (value)
	{
		value /= base;
		count++;
	}
	return (count);
}

static char		*ft_stralloc(int length)
{
	int		size;
	char	*ptr;

	size = length + 1;
	ptr = (char*)malloc(sizeof(char) * size);
	if (ptr)
	{
		while (size >= 0)
		{
			ptr[size] = '\0';
			size--;
		}
	}
	return (ptr);
}

char			*ft_uitoa_base(unsigned long long int value, int base)
{
	char	*str;
	int		size;
	int		result;

	if (base < 2 || base > 16)
		value = 0;
	size = get_length(value, base);
	str = ft_stralloc(size);
	if (value == 0)
		str[0] = '0';
	while (value)
	{
		result = (value % base);
		result = (result < 0) ? -result : result;
		str[size - 1] = g_base[result];
		value /= base;
		size--;
	}
	return (str);
}
