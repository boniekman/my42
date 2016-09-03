/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:55:10 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 11:14:42 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_array.h>

void	ft_arr_rev(void *arr_)
{
	int		i;
	int		j;
	void	*data;
	void	**arr;

	arr = arr_;
	i = 0;
	j = ft_arr_len(arr) - 1;
	while (i < j)
	{
		data = arr[i];
		arr[i] = arr[j];
		arr[j] = data;
		i++;
		j--;
	}
}
