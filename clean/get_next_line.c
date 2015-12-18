/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:10:12 by mbonowic          #+#    #+#             */
/*   Updated: 2015/12/18 16:11:15 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			check_endl(char *s)
{
	int			i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static int			gnl_start(t_ctrl *file, char **line, char **buf)
{
	if (file->sav == NULL)
		file->sav = ft_strnew(BUFF_SIZE + 1);
	if (line == NULL || file->fd < 0)
		return (-1);
	if (file->sav[0] != '\0')
	{
//		ft_putendl(file->sav);
		*buf = ft_strdup(file->sav);
		if (*buf == NULL)
			return (-1);
		bzero(file->sav, BUFF_SIZE + 1);
	}
	else
	{
		*buf = ft_strnew(BUFF_SIZE + 1);
		if (*buf == NULL)
			return (-1);
		file->flag = read(file->fd, *buf, BUFF_SIZE);
	if (file->flag < BUFF_SIZE)
		return (0);
	if (file ->flag == -1)
		return (-1);
	}
	return (1);
}

static int			bigger_buf(t_ctrl *file, char **buf)
{
	char			*tmp;
	char			*tmp2;

	tmp = ft_strdup(*buf);
	if (tmp == NULL)
		return (-1);
	tmp2 = ft_strnew(BUFF_SIZE + 1);
	if (tmp2 == NULL)
		return (-1);
	file->flag = read(file->fd, tmp2, BUFF_SIZE);
	if (file->flag == -1)
		return (-1);
	*buf = ft_strjoin(tmp, tmp2);;
	if (*buf == NULL)
		return (-1);
	free(tmp);
	free(tmp2);
	if (file->flag < BUFF_SIZE)
		return (0);
	return (1);
}

int					sav_left(t_ctrl *file, char **buf)
{
	file->sav = ft_strdup(ft_strchr(*buf, '\n') + 1);
	if (file->sav == NULL)
		return (-1);
	ft_bzero(ft_strchr(*buf, '\n'), BUFF_SIZE);
	return (1);
}

int					get_next_line(int const fd, char **line)
{
	static t_ctrl	file;
	char			*buf;

	file.fd = (int)fd;
	file.flag = gnl_start(&file, line, &buf);
	while (check_endl(buf) == 0 && file.flag == 1)
		file.flag = bigger_buf(&file, &buf);
	if (file.flag != -1)
	{
		if (sav_left(&file, &buf) == -1)
			return (-1);
		*line = ft_strdup(buf);
		if (*line == NULL)
			return (-1);
	}
	if (file.flag == 0 && ft_strlen(file.sav) == 0)
		return (0);
	return (file.flag);
}
