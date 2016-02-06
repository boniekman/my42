/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:10:12 by mbonowic          #+#    #+#             */
/*   Updated: 2016/01/24 14:56:23 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		check_endl(char *s)
{
	int			i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

static int		check_save_str(char **line, char *save)
{
	int			i;
	char		*tmp;

	i = 0;
	*line = ft_strnew(check_endl(save) + 1);
	if (*line != NULL)
	{
		while (save[i] && save[i] != '\n' && save[i] != EOF)
		{
			(*line)[i] = save[i];
			i++;
		}
		if (save[i] == '\n')
		{
			tmp = ft_strdup(&save[i + 1]);
			ft_bzero(save, BUFF_SIZE + 1);
			save = ft_strcpy(save, tmp);
			free(tmp);
			return (1);
		}
		else if (save[i] == EOF)
			return (0);
	}
	ft_bzero(save, BUFF_SIZE + 1);
	return (-1);
}

static int		bigger_line(char **line, int size)
{
	char		*tmp;

	if (*line != NULL)
	{
		size += (int)ft_strlen(*line);
		tmp = *line;
		*line = ft_strnew(size + 1);
		if (*line == NULL)
			return (-1);
		*line = ft_strcpy(*line, tmp);
		free(tmp);
	}
	else
	{
		*line = ft_strnew(size + 1);
		if (*line == NULL)
			return (-1);
	}
	return (1);
}

static int		buff_to_line(char **line, char *buff, char *save)
{
	int			i;
	int			pos;

	i = 0;
	pos = check_endl(*line);
	while (buff[i] && buff[i] != '\n' && buff[i] != EOF)
	{
		(*line)[pos + i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		save = ft_strcpy(save, &buff[i + 1]);
		return (1);
	}
	ft_bzero(buff, BUFF_SIZE + 1);
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char	save[BUFF_SIZE + 1];
	char		buff[BUFF_SIZE + 1];
	int			flag;

	if (line == NULL)
		return (-1);
	flag = check_save_str(line, save);
	if (flag != -1)
		return (flag);
	ft_bzero(buff, BUFF_SIZE + 1);
	while ((flag = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (bigger_line(line, flag) == -1)
			return (-1);
		flag = buff_to_line(line, buff, save);
		if (flag != 0)
			break ;
	}
	if ((*line)[0] != '\0' && flag == 0)
		return (1);
	return (flag);
}
