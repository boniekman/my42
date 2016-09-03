/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_create_elem__.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:55:45 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:56:35 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>
#include <stdlib.h>

t_lst_elem__	*ft_lst_create_elem__(void *data)
{
	t_lst_elem__	*new;

	if (!(new = (t_lst_elem__*)malloc(sizeof(t_lst_elem__))))
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
