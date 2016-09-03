/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:08:19 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:58:24 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	if (ft_strlen(s2) == 0)
		return ((char*)s1);
	while (s1[i])
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (s1[i + j] == s2[j] && s1[i + j] && s2[j])
				j++;
			if (s2[j] == '\0')
				return ((char*)s1 + i);
		}
		i++;
	}
	return (NULL);
}
