/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:00:36 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/25 14:09:53 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memory.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		((char*)dst)[i] = ((const char*)src)[i];
		i++;
	}
	return (dst);
}
