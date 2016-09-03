/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 02:52:02 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:55:16 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_array.h>

void	*ft_arr_new(size_t size)
{
	void	**arr;

	arr = (void**)malloc(size + 1);
	ft_memset(arr, 0, size + 1);
	arr[0] = NULL;
	return ((void*)arr);
}
