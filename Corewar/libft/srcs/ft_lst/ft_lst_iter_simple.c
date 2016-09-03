/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_iter_simple.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:56:01 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:56:32 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>

void	ft_lst_iter_simple(t_lst *lst, void (*f)(void *data))
{
	t_lst_elem__ *elem;
	t_lst_elem__ *next;

	elem = lst->head;
	while (elem)
	{
		next = elem->next;
		f(elem->data);
		elem = next;
	}
}
