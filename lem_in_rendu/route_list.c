/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 11:00:59 by mbonowic          #+#    #+#             */
/*   Updated: 2016/03/17 14:41:52 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_route		*new_route(int index)
{
	t_route	*new;

	if ((new = (t_route*)malloc(sizeof(t_route))) == NULL)
		return (NULL);
	new->node = index;
	new->ant = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void		add_route(t_route **route, int index)
{
	t_route	*tmp;
	t_route *new;

	if (*route == NULL)
		*route = new_route(index);
	else
	{
		tmp = *route;
		new = new_route(index);
		*route = new;
		tmp->prev = new;
		new->next = tmp;
	}
}

void		del_route(t_route **route)
{
	t_route	*tmp;

	if (*route != NULL)
	{
		tmp = *route;
		del_route(&(*route)->next);
		free(tmp);
	}
}

static void	print_route(t_route *r)
{
	while (r != NULL)
	{
		ft_putnbr(r->node);
		ft_putchar(' ');
		r = r->next;
	}
	ft_putchar('\n');
}

void		print_routes(t_all all)
{
	int		i;

	i = 0;
	while (all.routes[i] != NULL)
	{
		print_route(all.routes[i]);
		i++;
	}
}
