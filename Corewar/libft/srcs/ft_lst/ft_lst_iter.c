/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 02:51:57 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 11:16:13 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>

void	ft_lst_iter(t_lst *lst, void (*f)(void *data, void *context),
	void *context)
{
	t_lst_elem__ *elem;
	t_lst_elem__ *next;

	elem = lst->head;
	while (elem)
	{
		next = elem->next;
		f(elem->data, context);
		elem = next;
	}
}
