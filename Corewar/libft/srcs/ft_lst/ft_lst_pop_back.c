/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:56:14 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:56:25 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>
#include <stdlib.h>

void	*ft_lst_pop_back(t_lst *lst)
{
	void			*data;
	t_lst_elem__	*elem;

	if (!(elem = lst->tail))
		return (NULL);
	data = elem->data;
	ft_lst_del_elem__(lst, elem, NULL);
	return (data);
}
