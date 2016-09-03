/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:55:48 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:56:42 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>
#include <stdlib.h>

void	ft_lst_del(t_lst *lst, void (*delfn)(void*))
{
	t_lst_elem__ *elem;
	t_lst_elem__ *next;

	elem = lst->head;
	while (elem)
	{
		next = elem->next;
		ft_lst_del_elem__(lst, elem, delfn);
		elem = next;
	}
	lst->head = NULL;
	lst->tail = NULL;
	free(lst);
}
