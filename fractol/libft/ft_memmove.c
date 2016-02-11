/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:10:39 by mbonowic          #+#    #+#             */
/*   Updated: 2015/11/26 10:34:54 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*d;
	char	*s;

	i = 0;
	d = (char*)dst;
	s = (char*)src;
	if (len == 0)
		return (d);
	if (d > s)
	{
		i = len;
		while (--i >= 0)
		{
			d[i] = s[i];
		}
	}
	else
		while (i < (int)len)
		{
			d[i] = s[i];
			i++;
		}
	return (d);
}
