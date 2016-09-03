/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_iter_simple.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:55:02 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 11:14:32 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_array.h>

void	ft_arr_iter_simple(void *arr_, void (*f)(void *data))
{
	void **arr;

	arr = arr_;
	while (*arr)
	{
		f(*arr);
		arr++;
	}
}
