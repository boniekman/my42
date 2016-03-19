/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passage_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 21:02:35 by mbonowic          #+#    #+#             */
/*   Updated: 2016/03/10 13:39:57 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	is_in_list(t_node *list, char *name)
{
	int		flag;

	flag = -1;
	while (list)
	{
		if (ft_strcmp(name, list->name) == 0)
			flag = list->index;
		list = list->next;
	}
	return (flag);
}

static int	is_valid(t_all *all, char *n1, char *n2, char **error)
{
	int		a;
	int		b;
	if ((a = is_in_list(all->room, n1)) == -1)
		*error = ft_strjoin("ERROR: there are no ", n1);
	else if ((b = is_in_list(all->room, n2)) == -1)
		*error = ft_strjoin("ERROR: there are no ", n2);
	else
	{
		all->cons[a][b].con = 1;
		all->cons[b][a].con = 1;
		return (1);
	}
	return (-1);
}

void		zero_it(t_all *all)
{
	int		x;
	int		y;

	x = 0;
	while (x < all->size)
	{
		y = 0;
		while (y < all->size)
		{
			all->cons[x][y].con = 0;
			all->cons[x][y].weight = -1;
			all->cons[x][y].used = 0;
			y++;
		}
		x++;
	}
}

int			is_valid_pass(t_all *all, char *line, char **error)
{
	char	*n1;
	char	*n2;
	int		i;
	int		l;

	l = ft_strlen(line);
	while (line[i] != '\0' && line[i] != '-')
		i++;
	if (line[i] == '\0')
	{
		*error = ft_strdup("ERROR: Invalid path code <a>-<b>");
		return (-1);
	}
	else if (line[0] == 'L' || line[0] == '#')
	{
		*error = ft_strdup("ERROR: True hurts, but invalid chars too");
		return (-1);
	}
	else if ((n1 = ft_strnew(i + 1)) == NULL)
		return (-1);
	else if ((n2 = ft_strnew(l - i + 1)) == NULL)
		return (-1);
	n1 = ft_strncpy(n1, line, i);
	n2 = ft_strncpy(n2, &line[i + 1], l - i - 1);
	return (is_valid(all, n1, n2, error));
}
