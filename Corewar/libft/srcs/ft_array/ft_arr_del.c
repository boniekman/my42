/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:54:51 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 11:36:35 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_array.h>

void	del_fn__(void *elem, void *delfn_)
{
	void (*delfn)(void *elem);

	delfn = delfn_;
	if (delfn)
		delfn(elem);
}

void	ft_arr_del(void *arr, void (*delfn)(void *data))
{
	ft_arr_iter(arr, del_fn__, delfn);
	free(arr);
	arr = NULL;
}
