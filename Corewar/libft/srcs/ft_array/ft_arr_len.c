/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:55:05 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:55:17 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_array.h>

size_t	ft_arr_len(void *arr_)
{
	void	**arr;
	size_t	len;

	arr = arr_;
	len = 0;
	while (arr[len])
		len++;
	return (len);
}
