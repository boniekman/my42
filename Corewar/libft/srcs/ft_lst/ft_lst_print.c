/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 02:45:23 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 11:17:23 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>
#include <ft_stdio.h>

void	ft_lst_print(t_lst *lst, int (*p_fn)(void *data), char *sep)
{
	t_lst_elem__ *elem;

	elem = lst->head;
	while (elem)
	{
		p_fn(elem->data);
		elem = elem->next;
		ft_putstr((elem) ? sep : "\n");
	}
}
