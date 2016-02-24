/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:23:52 by mbonowic          #+#    #+#             */
/*   Updated: 2015/11/26 07:36:21 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2 == NULL || s2[0] == '\0')
		return ((char*)&s1[0]);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[j])
		{
			while ((s2[j] == s1[i + j] || s2[j] == '\0'))
			{
				if (s2[j] == '\0' && j != 0)
					return ((char*)&s1[i]);
				j++;
			}
		}
		i++;
		j = 0;
	}
	if (s2[0] == '\0')
		return ((char*)&s1[i]);
	return (NULL);
}
