/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:54:57 by mbonowic          #+#    #+#             */
/*   Updated: 2015/11/27 20:36:48 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	del((*alst)->content, (*alst)->content_size);
	tmp = (*alst)->next;
	free(*alst);
	*alst = NULL;
	if (tmp != NULL)
		ft_lstdel(&tmp, del);
}
