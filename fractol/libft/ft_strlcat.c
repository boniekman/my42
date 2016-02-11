/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:42:20 by mbonowic          #+#    #+#             */
/*   Updated: 2015/11/26 10:40:56 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	st;

	i = 0;
	st = 0;
	while (dst[i] != '\0' && size)
	{
		i++;
		st++;
		size--;
	}
	if (size == 0)
		return (st + ft_strlen((char*)src));
	i = 0;
	size += st;
	while (src[i] != '\0' && i + st < size - 1)
	{
		dst[st + i] = src[i];
		i++;
	}
	dst[st + i] = '\0';
	return (st + ft_strlen((char*)src));
}
