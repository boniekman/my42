/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:55:57 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:56:33 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>
#include <stdlib.h>

void	*ft_lst_get(t_lst *lst, int index)
{
	t_lst_elem__ *elem;

	elem = ft_lst_get_elem__(lst, index);
	if (elem)
		return (elem->data);
	return (NULL);
}
