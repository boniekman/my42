/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_link_all__.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 17:38:32 by sdelardi          #+#    #+#             */
/*   Updated: 2016/07/19 17:39:27 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>

void	ft_lst_link_all__(t_lst_elem__ *elem1,
		t_lst_elem__ *elem2, t_lst_elem__ *elem3)
{
	if (elem1)
		elem1->next = elem2;
	if (elem2)
	{
		elem2->prev = elem1;
		elem2->next = elem3;
	}
	if (elem3)
		elem3->prev = elem2;
}
