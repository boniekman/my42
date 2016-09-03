/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:44:57 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:58:28 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
		return ((char*)s + ft_strlen(s));
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	return (NULL);
}
