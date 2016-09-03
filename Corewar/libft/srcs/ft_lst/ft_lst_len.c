/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:56:02 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 11:16:27 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>

int		ft_lst_len(t_lst *lst)
{
	int				len;
	t_lst_elem__	*elem;

	len = 0;
	elem = lst->head;
	while (elem)
	{
		len++;
		elem = elem->next;
	}
	return (len);
}
