/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:44:24 by mbonowic          #+#    #+#             */
/*   Updated: 2016/03/10 09:06:04 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			is_number(char *s)
{
	int		i;
	while (ft_isdigit(s[i]) == 1)
		i++;
	if (s[i] == '\0')
		return (1);
	else
		return (-1);
}
static void	quick_free(char ***tab)
{
	int		i;

	i = 0;
	
	if (*tab != NULL)
	{
		while ((*tab)[i] != NULL)
		{
			free((*tab)[i]);
			i++;
		}
		free(*tab);
	}
}

int			is_room(char *s, char **error)
{
	char	**tab;
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != '-')
		i++;
	if ((tab = ft_split(s)) == NULL)
		*error = ft_strdup("ERROR: strsplit error");
	else if (tab[0][0] == '#')
	{
		return (0);
	}
	else if (s[i] == '-')
		return (2);
	else if (tab[0] == NULL || tab[1] == NULL || tab[2] == NULL || tab[3] != NULL || tab[0][0] == 'L')
		*error = ft_strdup("ERROR: wrong room's name");
	else if (is_number(tab[1]) == -1 || is_number(tab[2]) == -1)
		*error = ft_strdup("ERROR: room: <name> <int> <int>");
	else
	{
		quick_free(&tab);
		return (1);
	}
	quick_free(&tab);
	return (-1);
}

void		take_comm(t_all *all, char *line, char **error, int index)
{
	if (ft_strcmp(line, "##start") == 0)
	{
		if (all->start != -1)
			*error = ft_strdup("ERROR: multiple ##start");
		else
			if (read_restrictions(error, &line, 3) == 1)
				if (is_room(line, error) == 1)
				{
					all->start = index;
					add_room(all, line, error);
				}
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		if (all->end != -1)
			*error = ft_strdup("ERROR: multiple ##end");
		else
			if (read_restrictions(error, &line, 3) == 1)
				if (is_room(line, error) == 1)
				{
					all->end = index;
					add_room(all, line, error);
				}
	}
}

void		add_room(t_all *all, char *line, char **error)
{
	char	**tab;

	if ((tab = ft_split(line)) == NULL)
		*error = ft_strdup("ERROR: strsplit error");
	else
	{
		if (add_elem(&all->room, create_new(tab[0],
							ft_latoi(tab[1]), ft_latoi(tab[2]))) == -2)
			*error = ft_strdup("ERROR: multiple names");	
	}
	quick_free(&tab);
}
