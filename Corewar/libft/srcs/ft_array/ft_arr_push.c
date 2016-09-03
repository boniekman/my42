/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:55:09 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:55:14 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_array.h>

void	ft_arr_push(void *arr_, void *elem)
{
	void **arr;

	arr = arr_;
	while (*arr)
		arr++;
	*arr = elem;
	arr++;
	*arr = NULL;
}
