/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:58:59 by mbonowic          #+#    #+#             */
/*   Updated: 2015/11/26 07:55:42 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2 == NULL || s2[0] == '\0')
		return ((char*)s1);
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] == s2[j])
		{
			while ((s2[j] == s1[i + j] || s2[j] == '\0') && i + j <= n)
			{
				if (s2[j] == '\0')
					return ((char*)&s1[i]);
				j++;
			}
		}
		i++;
		j = 0;
	}
	return (NULL);
}
