/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:55:40 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:57:10 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memory.h>

void	*ft_memalloc(size_t size)
{
	void			*data;

	data = NULL;
	data = malloc(size);
	if (data == NULL)
		return (NULL);
	ft_memset(data, 0, size);
	return (data);
}
