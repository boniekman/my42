/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 23:38:00 by mbonowic          #+#    #+#             */
/*   Updated: 2016/03/02 09:56:15 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			g_it;

static void	to_max(t_all *all)
{
	if (search_max(all->a) <= all->size / 2)
	{
		while (search_max(all->a) != 0)
		{
			rotate(&all->a, 'a', all->dec);
			g_it++;
		}
	}
	else
	{
		while (search_max(all->a) != 0)
		{
			rev_rotate(&all->a, 'a', all->dec);
			g_it++;
		}
	}
	if (all->a->val > all->a->next->val)
	{
		swap_elems(&all->a, 'a', all->dec);
		g_it++;
	}
}

static void	to_min(t_all *all)
{
	if (search_min(all->a) <= all->size / 2)
	{
		while (search_min(all->a) != 0)
		{
			rotate(&all->a, 'a', all->dec);
			g_it++;
		}
	}
	else
	{
		while (search_min(all->a) != 0)
		{
			rev_rotate(&all->a, 'a', all->dec);
			g_it++;
		}
	}
	if (issorted(all->a) == 0)
	{
		push_elem(&all->a, &all->b, 'b', all->dec);
		g_it++;
	}
}

void		algo(t_all *all)
{
	g_it = 0;
	while (issorted(all->a) == 0)
	{
		if (all->a->val > all->a->next->val)
			swap_elems(&all->a, 'a', all->dec);
		else if (search_min(all->a) == 0)
			to_max(all);
		else
			to_min(all);
	}
	while (all->b)
	{
		push_elem(&all->b, &all->a, 'a', all->dec);
		g_it++;
	}
	if (all->dec == 2)
		ft_putnbr(g_it);
	write(1, "\n", 1);
}
