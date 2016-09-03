/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:58:57 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 12:02:33 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>

int		ft_lst_count(t_lst *lst, bool (*fn)(void *data))
{
	int				count;
	t_lst_elem__	*elem;

	count = 0;
	elem = lst->head;
	while (elem)
	{
		if (fn(elem->data))
			count++;
		elem = elem->next;
	}
	return (count);
}
