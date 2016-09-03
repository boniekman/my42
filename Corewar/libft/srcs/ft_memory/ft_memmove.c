/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:01:21 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:57:07 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memory.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int i;

	if (src > dst)
	{
		i = 0;
		while (i < len)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i++;
		}
	}
	else if (dst > src)
	{
		i = len - 1;
		while ((int)i >= 0)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i--;
		}
	}
	return (dst);
}
