/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 02:45:08 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 11:12:01 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_array.h>

void	ft_arr_print(void *arr_, int (*p_fn)(void *data))
{
	void	**arr;

	arr = arr_;
	ft_arr_iter_simple(arr, (void(*)(void*))p_fn);
}
