/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 16:01:32 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/07 17:10:14 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			set_row(char *str, t_map *map, int posx)
{
	char	**numbers;
	int		i;

	i = 0;
	numbers = ft_split(str);
	while (numbers[i] != NULL)
	{
		i++;
	}
	map->columns = i;
	map->tab[posx] = (t_point*)malloc(sizeof(t_point) * i);
	if (map->tab[posx] == NULL)
		return (-1);
	i = 0;
	while (i < map->columns)
	{
		map->tab[posx][i].z = ft_atoi(numbers[i]);
		if (!(map->max_z) || ft_atoi(numbers[i]) > map->max_z)
			map->max_z = ft_atoi(numbers[i]);
		free(numbers[i]);
		i++;
	}
	free(numbers);
	return (1);
}

int			set_map(t_map *map, char *filename)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	i = 0;
	if (fd < 0)
		return (-1);
	line = NULL;
	while (get_next_line(fd, &line))
	{
		map->rows++;
	}
	close(fd);
	map->tab = (t_point**)malloc(sizeof(t_point*) * (map->rows));
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (set_row(line, map, i) == -1)
			return (-1);
		i++;
	}
	free(line);
	return (1);
}
