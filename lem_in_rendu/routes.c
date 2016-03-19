/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 10:15:04 by mbonowic          #+#    #+#             */
/*   Updated: 2016/03/17 14:41:59 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		how_many(t_all *all)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (i < all->size)
	{
		if (all->cons[all->end][i].weight != -1)
			count++;
		i++;
	}
	return (count);
}

static int		is_anthg_to_do(t_all all, int min)
{
	int			i;

	i = 0;
	while (i < all.size)
	{
		if (all.cons[all.end][i].weight > -1)
			if (all.cons[all.end][i].weight > min)
				if (all.cons[all.end][i].used == 0)
					return (1);
		i++;
	}
	return (0);
}

static int		get_next(t_all *all, int i, int counter, int weight)
{
	int			j;

	j = 0;
	if (i == all->start)
		return (1);
	while (j < all->size)
	{
		if (all->cons[i][j].weight == weight && all->cons[i][j].used == 0)
		{
			add_route(&all->routes[counter], j);
			all->cons[i][j].used = 1;
			return (get_next(all, j, counter, weight - 1));
		}
		j++;
	}
	return (0);
}

static void		get_route(t_all *all, int i, int weight)
{
	static int	counter;

	add_route(&all->routes[counter], i);
	if (get_next(all, i, counter, weight - 1) == 0)
		del_route(&all->routes[counter]);
	else
	{
		all->cons[all->end][i].used = 1;
		counter++;
	}
}

int				search_routes(t_all *all, char **error)
{
	int			i;
	int			h_m;
	int			min;
	

	if ((h_m = how_many(all)) == 0)
		return (-1);
	all->routes = (t_route**)malloc(sizeof(t_route*) * (h_m + 1));
	if (all->routes == NULL)
		return (-1);
	all->routes[h_m] = NULL;
	min = 0;
	while (is_anthg_to_do(*all, min) == 1)
	{
		i = 0;
		while (i < all->size)
		{
			if (all->cons[all->end][i].weight == min && 
					all->cons[all->end][i].used != 1)
				get_route(all, i, min);
			i++;
		}
		min++;
	}
	return (1);
}
