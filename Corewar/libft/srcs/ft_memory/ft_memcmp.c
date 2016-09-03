/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:59:30 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:57:09 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memory.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (n)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		n--;
	}
	return (0);
}
