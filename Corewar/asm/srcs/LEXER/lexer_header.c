/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:03:14 by mbonowic          #+#    #+#             */
/*   Updated: 2016/07/18 18:04:16 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static t_header	*new_header(void)
{
	t_header	*header;

	header = (t_header*)malloc(sizeof(t_header));
	if (!header)
		exit(ft_putendl_fd("asm: allocation of header failed", STDERR_FILENO));
	ft_memset(header->prog_name, 0, PROG_NAME_LENGTH + 1);
	ft_memset(header->comment, 0, COMMENT_LENGTH + 1);
	header->magic = COREWAR_MAGIC;
	header->prog_size = 0;
	return (header);
}

static char		*split_header_information(char *line)
{
	char		*str;

	str = ft_strtrim(line);
	if (ft_str_count_char(str, '\"') != 2 || str[0] != '\"'
		|| str[ft_strlen(str) - 1] != '\"')
		return (NULL);
	ft_del_char(str, '\"');
	return (str);
}

static char		*get_header_info(int fd, char *field)
{
	char		*line;
	char		*info;

	line = NULL;
	info = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		ft_replace_char(line, '\t', ' ');
		if (ft_strchr(line, ';'))
			ft_strclr(ft_strchr(line, ';'));
		line = ft_strtrim_free(line);
		if (!ft_strncmp(line, field, ft_strlen(field)))
			info = split_header_information(line + ft_strlen(field));
		if (ft_str_count_char(line, ' ') == (int)ft_strlen(line) && !info)
		{
			ft_strdel(&line);
			continue;
		}
		if (line[0] != '#' || info)
			break ;
		ft_strdel(&line);
	}
	if (line)
		ft_strdel(&line);
	return (info);
}

static void		header_fatal_error(char *info, int fd, char *error)
{
	if (info)
		ft_strdel(&info);
	close(fd);
	ft_putstr_fd("asm: ", STDERR_FILENO);
	ft_putendl_fd(error, STDERR_FILENO);
	exit(1);
}

t_header		*get_header(int fd)
{
	char		*info;
	t_header	*header;

	info = NULL;
	header = new_header();
	if (!header)
		exit(1);
	info = get_header_info(fd, NAME_CMD_STRING);
	if (info == NULL || ft_strlen(info) > PROG_NAME_LENGTH || info[0] == 0)
		header_fatal_error(info, fd, "wrong name format");
	ft_strncpy(header->prog_name, info, ft_strlen(info));
	ft_strdel(&info);
	info = get_header_info(fd, COMMENT_CMD_STRING);
	if (info == NULL || ft_strlen(info) > COMMENT_LENGTH)
		header_fatal_error(info, fd, "wrong comment format");
	ft_strncpy(header->comment, info, ft_strlen(info));
	ft_strdel(&info);
	return (header);
}
