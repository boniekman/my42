/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:33:27 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/30 11:57:03 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>

void	ft_lst_remove(t_lst *lst, bool (*cmp_fn) (void*, void*),
	void *context, void (*del_fn)(void*))
{
	t_lst_elem__ *elem;
	t_lst_elem__ *next;

	elem = lst->head;
	while (elem)
	{
		next = elem->next;
		if (cmp_fn(elem->data, context))
			ft_lst_del_elem__(lst, elem, del_fn);
		elem = next;
	}
}
