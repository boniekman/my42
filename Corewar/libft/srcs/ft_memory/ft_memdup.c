/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:57:02 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:57:07 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memory.h>

void	*ft_memdup(void *data, size_t size)
{
	void *new;

	if (!(new = malloc(size)))
		return (NULL);
	ft_memcpy(new, data, size);
	return (new);
}
