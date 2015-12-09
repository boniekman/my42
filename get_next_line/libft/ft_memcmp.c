/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:32:07 by mbonowic          #+#    #+#             */
/*   Updated: 2015/11/25 18:59:17 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*c1;
	char	*c2;

	i = 0;
	c1 = (char*)s1;
	c2 = (char*)s2;
	if (n == 0)
		return (0);
	while (c1[i] == c2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)c1[i] - (unsigned char)c2[i]);
}
