/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_elem__.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:55:54 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:56:34 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>

t_lst_elem__	*ft_lst_get_elem__(t_lst *lst, int index)
{
	t_lst_elem__	*elem;

	elem = lst->head;
	while (elem && index--)
		elem = elem->next;
	return (elem);
}
