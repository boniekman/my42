/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_iter_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:55:58 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/29 13:35:54 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>

void	ft_lst_iter_elem__(t_lst *lst, void (*f)(t_lst_elem__ *elem))
{
	t_lst_elem__ *elem;
	t_lst_elem__ *next;

	elem = lst->head;
	while (elem)
	{
		next = elem->next;
		f(elem);
		elem = next;
	}
}
