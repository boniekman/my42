/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_insert_before.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 17:35:36 by sdelardi          #+#    #+#             */
/*   Updated: 2016/07/19 17:36:34 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>

void	ft_lst_insert_before(t_lst *lst, void *data, void *context)
{
	t_lst_elem__	*elem;
	int				index;

	index = ft_lst_get_index(lst, context);
	if (index == -1)
		return ;
	elem = ft_lst_get_elem__(lst, index);
	if (index == 0)
		ft_lst_push_front(lst, ft_lst_create_elem__(data));
	else
		ft_lst_link_all__(elem->prev, ft_lst_create_elem__(data), elem);
}
