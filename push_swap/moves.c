/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 17:08:56 by mbonowic          #+#    #+#             */
/*   Updated: 2016/03/02 09:29:29 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			swap_elems(t_list **list, char c, int d)
{
	int		tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return (0);
	tmp = (*list)->val;
	(*list)->val = (*list)->next->val;
	(*list)->next->val = tmp;
	if (d == 0 || d == 1)
	{
		write(1, "s", 1);
		write(1, &c, 1);
		write(1, " ", 1);
	}
	if (d == 1)
		print_list(*list);
	return (1);
}

int			push_elem(t_list **a, t_list **b, char c, int d)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*a)
	{
		tmp = *b;
		tmp2 = (*a)->next;
		*b = *a;
		(*b)->next = tmp;
		*a = tmp2;
	}
	if (d == 0 || d == 1)
	{
		write(1, "p", 1);
		write(1, &c, 1);
		write(1, " ", 1);
	}
	if (d == 1)
	{
		print_list(*a);
		print_list(*b);
	}
	return (1);
}

int			rotate(t_list **list, char c, int d)
{
	t_list	*tmp;
	t_list	*tmp2;

	if ((*list)->next)
	{
		tmp2 = *list;
		*list = (*list)->next;
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = tmp2;
		tmp->next->next = NULL;
	}
	if (d == 0 || d == 1)
	{
		write(1, "r", 1);
		write(1, &c, 1);
		write(1, " ", 1);
	}
	if (d == 1)
		print_list(*list);
	return (1);
}

int			rev_rotate(t_list **list, char c, int d)
{
	t_list	*tmp;
	t_list	*tmp2;

	if ((*list)->next)
	{
		tmp = *list;
		tmp2 = *list;
		while (tmp->next->next)
			tmp = tmp->next;
		*list = tmp->next;
		tmp->next = NULL;
		(*list)->next = tmp2;
	}
	if (d == 0 || d == 1)
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, " ", 1);
	}
	if (d == 1)
		print_list(*list);
	return (1);
}
