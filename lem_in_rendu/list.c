/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:24:55 by mbonowic          #+#    #+#             */
/*   Updated: 2016/03/04 15:15:20 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node		*create_new(char *name, int x, int y)
{
	t_node	*node;

	node = (t_node*)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->name = ft_strdup(name);
	if (name == NULL)
	{
		free(node);
		return (NULL);
	}
	node->x = x;
	node->y = y;
	node->ant = 0;
	node->next = NULL;
	return (node);
}

int			add_elem(t_node **list, t_node *node)
{
	t_node	*tmp;
	int		i;

	i = 1;
	if (node == NULL)
		return (-1);
	if (*list == NULL)
	{
		*list = node;
		(*list)->index = 0;
	}
	else
	{
		tmp = *list;
		while (tmp->next)
		{
			if (ft_strcmp(tmp->name, node->name) == 0)
				return (-2);
			tmp = tmp->next;
			i++;
		}
		if (ft_strcmp(tmp->name, node->name) == 0)
			return (-2);
		tmp->next = node;
		tmp->next->index = i;
	}
	return (1);
}

int			del_elem(t_node **list)
{
	t_node	*tmp;

	if (*list == NULL)
		return (0);
	else
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp->name);
		free(tmp);
		return (1);
	}
}

int			del_list(t_node **list)
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
