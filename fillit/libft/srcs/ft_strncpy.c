/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:15:21 by ngrasset          #+#    #+#             */
/*   Updated: 2015/11/24 16:18:27 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*start;

	start = dst;
	while (n > 0)
	{
		if (*src)
		{
			*dst = *src;
			src++;
		}
		else
		{
			*dst = '\0';
		}
		dst++;
		n--;
	}
	return (start);
}
