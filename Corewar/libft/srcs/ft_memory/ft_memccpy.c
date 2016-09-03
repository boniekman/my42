/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:56:40 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:57:10 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memory.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	char			*ptr_dst;
	const char		*ptr_src;

	ptr_dst = (char*)dst;
	ptr_src = (const char*)src;
	i = 0;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		if (ptr_src[i] == c)
			return ((void*)ptr_dst + i + 1);
		i++;
	}
	return (NULL);
}
