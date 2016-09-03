/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del_elem__.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:55:46 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 11:17:06 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>
#include <stdlib.h>

void		ft_lst_del_elem__(t_lst *lst, t_lst_elem__ *elem,
	void (*delfn)(void*))
{
	ft_lst_link__(elem->prev, elem->next);
	if (!elem->prev)
		lst->head = elem->next;
	if (!elem->next)
		lst->tail = elem->prev;
	if (delfn)
		delfn(elem->data);
	elem->data = NULL;
	elem->prev = NULL;
	elem->next = NULL;
	free(elem);
}
