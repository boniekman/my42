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

int				check_endl(char *s)
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
		file->buf = ft_strnew(BUFF_SIZE);
		if (file->buf == NULL)
			return (-1);
		file->flag = read(file->fd, file->buf, BUFF_SIZE);
	}
	else if (check_endl(file->fd))
		return (1);
	else
	{
		tmp = ft_strnew(BUFF_SIZE);
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

int					bigger_buf(t_ctrl *file)
{

}

char				*gnl_copy(char **buf)
{
}

int					get_next_line(int const fd, char **line)
{
	static s_ctrl	file;
	int				flag;

	file.fd = (int)fd;
	flag = gnl_start(&file, line);
	if (flag)
	{
		while (check_endl(file->buf))
		{
			bigger_buf(&file);
		}
		*line = gnl_copy(&file);
	}
	return ();
}
