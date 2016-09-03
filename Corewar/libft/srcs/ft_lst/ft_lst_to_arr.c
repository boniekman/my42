/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:56:20 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:56:22 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>
#include <ft_array.h>

static void	push_on_arr(void *data, void *arr)
{
	ft_arr_push(arr, data);
}

void		*ft_lst_to_arr(t_lst *lst, size_t size)
{
	void **arr;

	arr = ft_arr_new(ft_lst_len(lst) * size);
	ft_lst_iter(lst, push_on_arr, arr);
	return (arr);
}
