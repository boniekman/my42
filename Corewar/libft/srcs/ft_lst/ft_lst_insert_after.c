/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_insert_after.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 17:36:49 by sdelardi          #+#    #+#             */
/*   Updated: 2016/07/19 17:37:18 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>

void	ft_lst_insert_after(t_lst *lst, void *data, void *context)
{
	t_lst_elem__	*elem;
	int				index;

	index = ft_lst_get_index(lst, context);
	if (index == -1)
		return ;
	elem = ft_lst_get_elem__(lst, index);
	ft_lst_link_all__(elem, ft_lst_create_elem__(data), elem->next);
}
