/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:55:53 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 11:15:47 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>
#include <stdbool.h>
#include <stdlib.h>

void	*ft_lst_find(t_lst *lst, bool (*f)(void *data, void *context),
	void *context)
{
	t_lst_elem__	*elem;

	elem = lst->head;
	while (elem)
	{
		if (f(elem->data, context))
			return (elem->data);
		elem = elem->next;
	}
	return (NULL);
}
