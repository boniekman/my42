/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_link__.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:56:08 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 11:16:39 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>

void	ft_lst_link__(t_lst_elem__ *elem1, t_lst_elem__ *elem2)
{
	if (elem1)
		elem1->next = elem2;
	if (elem2)
		elem2->prev = elem1;
}
