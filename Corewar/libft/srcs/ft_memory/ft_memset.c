/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:03:15 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:57:06 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memory.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	char			*test;

	test = (char*)b;
	i = 0;
	while (i < len)
	{
		test[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
