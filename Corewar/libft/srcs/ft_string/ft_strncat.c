/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:59:04 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:58:26 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	char	*start;

	start = s1;
	i = 0;
	while (*s1)
		s1++;
	while (s2[i] && n)
	{
		s1[i] = s2[i];
		i++;
		n--;
	}
	s1[i] = '\0';
	return (start);
}
