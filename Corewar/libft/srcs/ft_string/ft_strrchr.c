/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:06:32 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:58:24 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*ft_strrchr(const char *s, int c)
{
	char *ptr;

	ptr = NULL;
	if (c == '\0')
		return ((char*)s + ft_strlen(s));
	while (*s)
	{
		if (*s == c)
			ptr = (char*)s;
		s++;
	}
	return (ptr);
}
