/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 14:04:36 by mbonowic          #+#    #+#             */
/*   Updated: 2016/03/17 11:01:34 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			print_list(t_node *list)
{
	while (list)
	{
		ft_putnbr(list->index);
		ft_putchar(' ');
		ft_putstr(list->name);
		ft_putchar(' ');
		ft_putnbr(list->x);
		ft_putchar(' ');
		ft_putnbr(list->y);
		ft_putchar('\n');
		list = list->next;
	}
	ft_putendl("");
	return (1);
}

int			print_cons(t_all all)
{
	int		x;
	int		y;

	x = 0;
	while (x < all.size)
	{
		y = 0;
		while (y < all.size)
		{
			ft_putnbr(all.cons[x][y].con);
			ft_putchar(' ');
			y++;
		}
		x++;
		ft_putchar('\n');
	}
	ft_putchar('\n');
	return (1);
}

int			print_weights(t_all all)
{
	int		x;
	int		y;

	x = 0;
	while (x < all.size)
	{
		y = 0;
		while (y < all.size)
		{
			ft_putnbr(all.cons[x][y].weight);
			ft_putchar(' ');
			y++;
		}
		x++;
		ft_putchar('\n');
	}
	ft_putchar('\n');
	return (1);
}

int		print_arr(t_all all)
{
	int	i;

	i = 0;
	while (i < all.size)
	{
		ft_putendl(all.arr_of_rooms[i].name);
		i++;
	}
	return (1);
}
