/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 09:21:36 by mbonowic          #+#    #+#             */
/*   Updated: 2015/11/27 12:46:40 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(src);
	while (src[i] != '\0' && i < n && i < l)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (l < n)
	{
		dst[l] = '\0';
		l++;
	}
	return (dst);
}
