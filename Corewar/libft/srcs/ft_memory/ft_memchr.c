/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:57:55 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:57:09 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memory.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str;

	str = (unsigned char*)s;
	while (n)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}
