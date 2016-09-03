/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:56:18 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:56:23 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>

void	ft_lst_push_front(t_lst *lst, void *data)
{
	t_lst_elem__ *elem;

	elem = ft_lst_create_elem__(data);
	ft_lst_link__(elem, lst->head);
	if (!lst->tail)
		lst->tail = elem;
	lst->head = elem;
}
