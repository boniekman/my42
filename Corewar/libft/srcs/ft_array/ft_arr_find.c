/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:54:57 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 11:11:43 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_array.h>

void	*ft_arr_find(void *arr_, bool (*cmp_fn)(void *data, void *context),
	void *context)
{
	void **arr;

	arr = arr_;
	while (arr)
	{
		if (cmp_fn(*arr, context))
			return (*arr);
		arr++;
	}
	return (NULL);
}
