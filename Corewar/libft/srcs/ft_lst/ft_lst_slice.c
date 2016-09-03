/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_slice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:56:19 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:56:23 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>
#include <stdlib.h>

t_lst	*ft_lst_slice(t_lst *lst, int begin, int end)
{
	t_lst			*new;
	t_lst_elem__	*elem;
	size_t			len;

	len = ft_lst_len(lst);
	if (end > (int)len || end < 0 || begin < 0 || begin > end)
		return (NULL);
	new = ft_lst_new();
	elem = ft_lst_get_elem__(lst, begin);
	while (elem && begin < end)
	{
		ft_lst_push_back(new, elem->data);
		begin++;
		elem = elem->next;
	}
	return (new);
}
