/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:04:38 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:58:24 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	int i;

	i = 0;
	while (src[i] && n)
	{
		dst[i] = src[i];
		i++;
		n--;
	}
	while (n)
	{
		dst[i] = '\0';
		n--;
		i++;
	}
	return (dst);
}
