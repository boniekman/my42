/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:56:17 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:56:24 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>
#include <ft_stdio.h>

void	ft_lst_push_back(t_lst *lst, void *data)
{
	t_lst_elem__	*elem;

	elem = ft_lst_create_elem__(data);
	ft_lst_link__(lst->tail, elem);
	if (!lst->head)
		lst->head = elem;
	lst->tail = elem;
}
