/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:10:12 by mbonowic          #+#    #+#             */
/*   Updated: 2015/12/09 18:08:55 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		check_endl(char *s)
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

static int			gnl_start(t_ctrl *file, char **line)
{
	char			*tmp;

	if (file->fd < 0 || line == NULL)
		return (-1);
	if (file->buf == NULL)
	{
		file->buf = ft_strnew(BUFF_SIZE + 1);
		if (file->buf == NULL)
			return (-1);
		file->flag = read(file->fd, file->buf, BUFF_SIZE);
	}
	else
	{
		if (check_endl(file->buf))
			return (1);
		tmp = ft_strnew(BUFF_SIZE + 1);
		if (tmp == NULL)
			return (-1);
		file->flag = read(file->fd, tmp, BUFF_SIZE);
		file->buf = ft_strjoin(file->buf, tmp);
		if (file->buf == NULL)
			return (-1);
		free(tmp);
	}
	return (1);
}

static int			bigger_buf(t_ctrl *file)
{
	char			*tmp;
	char			*tmp2;
	
	tmp = ft_strdup(file->buf);
	if (tmp == NULL)
		return (-1);
	free(file->buf);
	file->buf = NULL;
	tmp2 = ft_strnew(BUFF_SIZE + 1);
	if (tmp2 == NULL)
		return (-1);
	file->flag = read(file->fd, tmp2, BUFF_SIZE);
	file->buf = ft_strjoin(tmp, tmp2);
	if (file->buf == NULL)
		return (-1);
	free(tmp);
	free(tmp2);
	return (1);
}

static char			*gnl_copy(t_ctrl *file, int i, int j)
{
	char			*tmp;
	char			*tmp2;

	tmp = ft_strdup(file->buf);
	if (tmp == NULL)
		return (NULL);
	free(file->buf);
	while (tmp[i] != '\n' && tmp[i] != '\0')
	{
		i++;
	}
	tmp2 = ft_strnew(i + 1);
	tmp2 = ft_strncat(tmp2, tmp, i);
	file->buf = ft_strnew(ft_strlen(tmp) - i);
	if (tmp[i] != '\0' && tmp[i + 1] != '\0')
	{
		i++;
		while (tmp[i + j] != '\0')
		{
			file->buf[j] = tmp[i + j];
			j++;
		}
	}
	free(tmp);
	return (tmp2);
}

int					get_next_line(int const fd, char **line)
{
	static t_ctrl	file;
	int				flag;

	file.fd = (int)fd;
	flag = gnl_start(&file, line);
	if (flag)
	{
		while (check_endl(file.buf) == 0 && file.flag)
		{
			if (bigger_buf(&file) == -1)
				return (-1);
			if (file.flag == 0)
				break ;
		}
		*line = gnl_copy(&file, 0, 0);
		if (file.flag == 0 && check_endl(file.buf) == 0)
			flag = 0;
	}
	return (flag);
}
