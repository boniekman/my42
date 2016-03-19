/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 14:21:33 by mbonowic          #+#    #+#             */
/*   Updated: 2016/03/17 14:41:54 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				color_graph(t_all *all, int	weight, int index, char **error)
{
	int			i;

	i = 0;
	while (i < all->size)
	{
		if (all->cons[index][i].con == 1)
		{
			if (all->cons[index][i].weight == -1 || all->cons[index][i].weight > weight)
			{
				if (index == all->end)
				{
					all->cons[index][i].weight = weight;
					return (1);
				}
				all->cons[index][i].weight = weight;
				color_graph(all, weight + 1, i, error);
			}
		}
		i++;
	}
	if (*error != NULL)
		return (-1);
	return (1);
}

int				algo(t_all *all, char **error)
{
	color_graph(all, 0, all->start, error);
	if (search_routes(all, error) == -1)
		return (-1);
	print_routes(*all);
	return (1);
}
