/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 19:38:55 by mbonowic          #+#    #+#             */
/*   Updated: 2015/11/27 20:22:33 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*tmp;
	t_list	*new;

	if (lst != NULL)
	{
		head = ft_lstnew(lst->content, lst->content_size);
		if (head == NULL)
			return (NULL);
		head = f(head);
		lst = lst->next;
		tmp = head;
	}
	while (lst != NULL)
	{
		new = ft_lstnew(lst->content, lst->content_size);
		if (tmp == NULL)
			return (NULL);
		new = f(new);
		lst = lst->next;
		tmp->next = new;
	}
	return (head);
}
