/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:10:12 by mbonowic          #+#    #+#             */
/*   Updated: 2015/12/08 15:26:09 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_endl(char *s)
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

int		gnl_conditions(int fd, char **buf, char **line)
{
	int			res_read;

	if (fd < 0 || line == NULL)
		return (-1);
	*buf = ft_strnew(BUFF_SIZE + 1);
	if (*buf == NULL)
		return (-1);
	res_read = read(fd, *buf, BUFF_SIZE);
	if (res_read == -1)
	{
		free(*buf);
		return (-1);
	}
	if (res_read == 0)
		return (0);
	return (1);
}

char	*bigger_buf(char *s, int fd, int *flag)
{
	int		i;
	char	*new;

	new = ft_strnew(ft_strlen(s) + BUFF_SIZE + 1);
	if (new == NULL)
		return (NULL);
	new = ft_strcpy(new, s);
	i = read(fd, &new[ft_strlen(s)], BUFF_SIZE);
	if (i < 0)
		return (NULL);
	if (i == 0)
		*flag = 0;
	return (new);
}

char	*cut_last(char **s)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (*s[i] != '\n' && *s[i] != '\0')
		i++;
	if (*s[i] == '\n')
	{
		*s[i] = '\0';
		tmp = ft_strdup(*s);
	}
	return (tmp);
}

int		get_next_line(int const fd, char **line)
{
	char		*buf;
	static char	*tmp;
	int			flag;

	flag = gnl_conditions((int)fd, &buf, line);
	if (flag == -1)
		return (-1);
	if (tmp != NULL)
		buf = ft_strjoin(tmp, buf);
		tmp = NULL;
	if (flag == 0)
	{
		*line = ft_strdup(buf);
	}
	else
	{
		while (!check_endl(buf) && flag)
		{
			buf = bigger_buf(buf, fd, &flag);
			if (buf == NULL)
				return (-1);
		}
		tmp = cut_last(&buf);
		*line = ft_strdup(buf);
	}
	free(buf);
	return (flag);
}
