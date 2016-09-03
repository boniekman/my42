/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:55:03 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 11:13:27 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_array.h>

void	ft_arr_iter(void *arr_, void (*f)(void *elem, void *context),
	void *context)
{
	int		i;
	void	**arr;

	arr = arr_;
	i = 0;
	while (arr[i])
	{
		f(arr[i], context);
		i++;
	}
}
