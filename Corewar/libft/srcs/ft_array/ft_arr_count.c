/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:51:25 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 11:54:16 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int		ft_arr_count(void *arr_, bool (*fn)(void *data))
{
	int		i;
	int		count;
	void	**arr;

	i = 0;
	count = 0;
	arr = arr_;
	while (arr[i])
	{
		if (fn(arr[i]))
			count++;
		i++;
	}
	return (count);
}
