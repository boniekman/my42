/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:35:19 by mbonowic          #+#    #+#             */
/*   Updated: 2016/03/17 10:57:23 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

long long	how_many_ants(char **error)
{
	char	*line;
	int		flag;
	int		i;
	int		ants;

	line = NULL;
	i = 0;
	flag = read_restrictions(error, &line, 3);
	if (flag == -1)
		return (-1);
	while (line[i] != '\0' && (flag = ft_isdigit(line[i]) == 1))
		i++;
	if (flag == 0)
		*error = ft_strdup("Error: No ants, or sad, negative ones :(");
	else
	{
		ants = ft_latoi(line);
		if (ants > 0)
			return (ants);
		*error = ft_strdup("Error: No ants");
	}
	return (-1);
}

int			take_rooms(t_all *all, char **error)
{
	char	*line;
	int		flag;
	int		i;

	line = NULL;
	i = 0;
	while (read_restrictions(error, &line, 0) > 0)
	{
		if ((flag = is_room(line, error)) == -1)
			return (-1);
		else if (flag == 2)
		{
			all->size = i;
			return (make_cons(all, error, line));
		}
		else if (flag == 0)
			take_comm(all, line, error, i);
		else
			add_room(all, line, error);
		if (*error != NULL)
			return (-1);
		i++;
	}
	if (line != NULL)
		free(line);
	return (-1);
}

int			make_cons(t_all *all, char **error, char *line)
{
	int		i;

	i = 0;
	if ((all->cons = (t_cons**)malloc(all->size * sizeof(t_cons*))) == NULL)
		return (-1);
	while (i < all->size)
	{
		if ((all->cons[i] = (t_cons*)malloc(all->size * sizeof(t_cons))) == NULL)
			return (-1);
		i++;
	}
	zero_it(all);
	if (is_valid_pass(all, line, error) == -1)
		return (-1);
	ft_bzero(line, ft_strlen(line));
	while (read_restrictions(error, &line, 3) > 0)
		if (is_valid_pass(all, line, error) == -1)
			return (-1);
	if (*error != NULL)
		return (-1);
	if (line != NULL)
		free(line);
	return (1);
}

int			arr_of_rooms(t_all *all, char **error)
{
	int		i;

	i = 0;
	if ((all->arr_of_rooms = (t_node*)malloc(sizeof(t_node) * all->size)) == NULL)
		return (-1);
	while (i < all->size)
	{
		all->arr_of_rooms[i] = *all->room;
		all->room = all->room->next;
		i++;
	}
	return (1);
}

int			init(t_all *all, char **error)
{
	all->start = -1;
	all->end = -1;
	if ((all->ants = how_many_ants(error)) == -1)
		return (-1);
	if (take_rooms(all, error) == -1)
	{
		if (*error == NULL)
			*error = ft_strdup("ERROR: Not enough data, at least 1 room and passage");
		return (-1);
	}
	if (arr_of_rooms(all, error) == -1)
		return (-1);
	return (1);
}
