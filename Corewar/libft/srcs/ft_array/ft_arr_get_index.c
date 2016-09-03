/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_get_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:55:01 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 11:14:22 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_array.h>

int		ft_arr_get_index(void *arr_, bool (*cmp_fn)(void *data, void *context),
	void *context)
{
	int		i;
	void	**arr;

	i = 0;
	arr = arr_;
	while (arr[i])
	{
		if (cmp_fn(arr[i], context))
			return (i);
		i++;
	}
	return (-1);
}
