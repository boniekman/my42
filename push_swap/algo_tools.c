/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 08:00:51 by mbonowic          #+#    #+#             */
/*   Updated: 2016/03/02 09:57:08 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			search_min(t_list *l)
{
	int		i;
	int		min;
	int		r;

	i = 0;
	r = 0;
	min = l->val;
	while (l)
	{
		if (min > l->val)
		{
			min = l->val;
			r = i;
		}
		l = l->next;
		i++;
	}
	return (r);
}

int			search_max(t_list *l)
{
	int		i;
	int		max;
	int		r;

	i = 0;
	r = 0;
	max = l->val;
	while (l)
	{
		if (max < l->val)
		{
			max = l->val;
			r = i;
		}
		l = l->next;
		i++;
	}
	return (r);
}

int			issorted(t_list *list)
{
	while (list->next)
	{
		if (list->val < list->next->val)
			list = list->next;
		else
			break ;
	}
	if (list->next)
		return (0);
	else
		return (1);
}
