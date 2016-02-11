/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 16:01:32 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/10 20:18:25 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_line(char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (-1);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0 && str[i] != ' ' && str[i] != '-')
			return (-1);
		i++;
	}
	return (1);
}

static int	words(char *str)
{
	int		r;
	int		i;

	i = 0;
	r = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && str[i - 1] != ' ')
			r++;
		i++;
	}
	return (r);
}

static int	check_and_count_lines(int fd, char *line)
{
	int		r;
	int		f;
	int		l;

	r = 0;
	f = 0;
	while (f != -1 && (f = get_next_line(fd, &line)) > 0)
	{
		line = ft_strtrim(line);
		if (check_line(line) == -1)
			f = -1;
		if (!l)
			l = words(line);
		else if (l != words(line))
			f = -1;
		r++;
	}
	close(fd);
	if (f == -1 || r == 0)
	{
		ft_putendl("Smthg wrong with GNL, invalid file");
		free(line);
		end(NULL);
	}
	return (r);
}

static int	set_row(char *str, t_map *map, int posx)
{
	char	**numbers;
	int		i;

	i = 0;
	numbers = ft_split(str);
	if (numbers == NULL)
		return (-1);
	while (numbers[i] != NULL)
		i++;
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

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = NULL;
	map->rows = check_and_count_lines(fd, line);
	map->tab = (t_point**)malloc(sizeof(t_point*) * (map->rows));
	fd = open(filename, O_RDONLY);
	if (map->tab == NULL)
		return (-1);
	while (get_next_line(fd, &line) > 0)
	{
		if (set_row(line, map, i) == -1)
			return (-1);
		i++;
	}
	free(line);
	return (1);
}
