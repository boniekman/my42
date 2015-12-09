/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:20:44 by mbonowic          #+#    #+#             */
/*   Updated: 2015/11/23 13:05:52 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	i = (int)ft_strlen(s1);
	j = 0;
	s2 = (char*)malloc(i * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	while (j <= i)
	{
		s2[j] = s1[j];
		j++;
	}
	return (s2);
}
