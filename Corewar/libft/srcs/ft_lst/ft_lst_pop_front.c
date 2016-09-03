/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:56:15 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 11:16:02 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>
#include <stdlib.h>

void	*ft_lst_pop_front(t_lst *lst)
{
	void			*data;
	t_lst_elem__	*elem;

	if (!(elem = lst->head))
		return (NULL);
	data = elem->data;
	ft_lst_del_elem__(lst, elem, NULL);
	return (data);
}
