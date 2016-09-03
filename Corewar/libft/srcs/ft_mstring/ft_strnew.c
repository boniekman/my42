/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:04:55 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:58:43 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mstring.h>

char	*ft_strnew(size_t size)
{
	char			*ptr;
	unsigned int	i;

	ptr = malloc(sizeof(char) * size + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
