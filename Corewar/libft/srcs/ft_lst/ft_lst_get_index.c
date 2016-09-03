/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:55:56 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:56:40 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>

int		ft_lst_get_index(t_lst *lst, void *data)
{
	t_lst_elem__	*elem;
	int				index;

	index = 0;
	elem = lst->head;
	while (elem)
	{
		if (elem->data == data)
			return (index);
		index++;
		elem = elem->next;
	}
	return (-1);
}
