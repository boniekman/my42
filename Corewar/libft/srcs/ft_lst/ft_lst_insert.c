/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 17:37:38 by sdelardi          #+#    #+#             */
/*   Updated: 2016/07/19 17:38:21 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>

void	ft_lst_insert(t_lst *lst, void *data, int index)
{
	t_lst_elem__	*elem;

	if (index == 0)
		ft_lst_push_front(lst, data);
	else if (index == ft_lst_len(lst))
		ft_lst_push_back(lst, data);
	else
	{
		elem = ft_lst_get_elem__(lst, index);
		ft_lst_link_all__(elem->prev, ft_lst_create_elem__(data), elem);
	}
}
