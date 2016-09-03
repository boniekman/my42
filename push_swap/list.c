/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:24:55 by mbonowic          #+#    #+#             */
/*   Updated: 2016/03/01 23:27:38 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list		*create_new(int val)
{
	t_list	*node;

	node = (t_list*)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->val = val;
	node->next = NULL;
	return (node);
}

int			add_elem(t_list **list, t_list *node)
{
	t_list	*tmp;

	if (node == NULL)
		return (-1);
	if (*list == NULL)
		*list = node;
	else
	{
		tmp = *list;
		while (tmp->next)
		{
			if (node->val == tmp->val)
				return (-1);
			tmp = tmp->next;
		}
		if (node->val == tmp->val)
			return (-1);
		tmp->next = node;
	}
	return (1);
}

int			del_elem(t_list **list)
{
	t_list	*tmp;

	if (*list == NULL)
		return (0);
	else
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
		return (1);
	}
}

int			del_list(t_list **list)
{
	int		f;

	f = 1;
	while (f)
	{
		f = del_elem(list);
	}
	*list = NULL;
	return (1);
}

int			print_list(t_list *list)
{
	while (list)
	{
		ft_putnbr(list->val);
		ft_putchar(' ');
		list = list->next;
	}
	ft_putchar('\n');
	return (1);
}
