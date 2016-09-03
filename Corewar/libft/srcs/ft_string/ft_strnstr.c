/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:05:31 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:58:25 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int i;
	int j;
	int k;

	i = 0;
	if (ft_strlen(s2) == 0)
		return ((char*)s1);
	while (s1[i] && n)
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			k = n;
			while (s1[i + j] == s2[j] && s1[i + j] && s2[j] && k--)
				j++;
			if (s2[j] == '\0')
				return ((char*)s1 + i);
		}
		i++;
		n--;
	}
	return (NULL);
}
