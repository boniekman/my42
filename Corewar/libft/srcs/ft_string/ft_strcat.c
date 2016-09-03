/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:43:54 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:58:29 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	char	*start;

	start = s1;
	i = 0;
	while (*s1)
		s1++;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (start);
}
