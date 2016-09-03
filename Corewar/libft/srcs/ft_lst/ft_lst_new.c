/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:56:12 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/03 10:56:26 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_lst.h>
#include <stdlib.h>

t_lst	*ft_lst_new(void)
{
	t_lst	*lst;

	if (!(lst = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	lst->head = NULL;
	lst->tail = NULL;
	return (lst);
}
