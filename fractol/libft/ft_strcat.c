/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:05:59 by mbonowic          #+#    #+#             */
/*   Updated: 2015/11/24 15:24:25 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		st;

	i = 0;
	st = ft_strlen(s1);
	while (s2[i] != '\0')
	{
		s1[st + i] = s2[i];
		i++;
	}
	s1[st + i] = '\0';
	return (s1);
}