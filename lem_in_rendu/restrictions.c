/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restrictions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:55:04 by mbonowic          #+#    #+#             */
/*   Updated: 2016/03/04 13:04:50 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	se_restrictions(char **line, int choice)
{
	if (choice == 3)
	{
		if (ft_strcmp(*line, "##start") == 0 || ft_strcmp(*line, "##end") == 0)
			return (-1);
	}
	else if (choice == 2)
	{
		if (ft_strcmp(*line, "##start") == 0)
			return (-1);
	}
	else if (choice == 1)
	{
		if (ft_strcmp(*line, "##end") == 0)
			return (-1);
	}
	return (1);
}

int			read_restrictions(char **error, char **line, int c)
{
	int		flag;

	flag = get_next_line(0, line);
	ft_putendl(*line);
	if (flag == -1)
	{
		*error = ft_strdup("Error: stdin read error");
		return (-1);
	}
	else if (flag == 0)
		return (0);
	else if (*line[0] == '#' && ft_strcmp(*line, "##start") != 0
			&& ft_strcmp(*line, "##end") != 0)
	{
			return (read_restrictions(error, line, c));
	}
	else if (se_restrictions(line, c) == -1)
	{
		*error = ft_strdup("Error: start/end commands invalid place");
		return (-1);
	}
	return (1);
}
