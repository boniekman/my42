/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:55:44 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:56:36 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>

t_lst	*ft_lst_cpy(t_lst *lst, void *(*f)(void *data))
{
	t_lst			*new;
	t_lst_elem__	*elem;

	new = ft_lst_new();
	elem = lst->head;
	while (elem)
	{
		if (f)
			ft_lst_push_back(new, f(elem->data));
		else
			ft_lst_push_back(new, elem->data);
		elem = elem->next;
	}
	return (new);
}
