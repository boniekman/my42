/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:54:43 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:55:21 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_array.h>

static void	push_wrapper(void *data, void *new_arr)
{
	ft_arr_push(new_arr, data);
}

void		*ft_arr_cpy(void *arr)
{
	void	**new_arr;

	new_arr = ft_arr_new(ft_arr_len(arr));
	ft_arr_iter(arr, push_wrapper, new_arr);
	return ((void*)new_arr);
}
