/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 11:03:05 by mbonowic          #+#    #+#             */
/*   Updated: 2016/07/18 16:09:20 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			check_magic(char *buffer)
{
	int		part;

	ft_memcpy(&part, buffer, sizeof(unsigned int));
	return ((int)COREWAR_TRUE_MAGIC == part);
}

int			get_header_body(int fd, t_champ *champ)
{
	char		buffer[HEADER_SIZE];
	unsigned	size;

	size = 0;
	ft_memset(buffer, 0, HEADER_SIZE);
	if (read(fd, buffer, HEADER_SIZE) != HEADER_SIZE ||
			check_magic(buffer) == FALSE)
		return (-1);
	if ((champ->name = ft_strdup(buffer + sizeof(unsigned int))) == NULL)
		return (-1);
	ft_memcpy(&size, buffer + sizeof(unsigned int) + PROG_NAME_LENGTH + 4,
			sizeof(unsigned int));
	if ((size = reverse_int(size)) > CHAMP_MAX_SIZE)
		return (-1);
	champ->size = size;
	if ((champ->body = ft_strnew(size)) == NULL)
		return (-1);
	if (read(fd, champ->body, size) != size)
		return (-1);
	ft_memset(buffer, 0, HEADER_SIZE);
	if (read(fd, buffer, 10) != 0)
		return (-1);
	return (1);
}

int			open_champ_file(char *filename)
{
	if (!ft_strrchr(filename, '.') ||
			!ft_strequ(ft_strrchr(filename, '.'), ".cor"))
		return (-1);
	return (open(filename, O_RDONLY));
}

int			parse_champ(char *filename, int id)
{
	int			fd;
	t_champ		*champ;

	if ((fd = open_champ_file(filename)) == -1)
		fatal_exit_vm("invalid file provided for the champion");
	if ((champ = (t_champ*)malloc(sizeof(t_champ))) == NULL)
		fatal_exit_vm("malloc error");
	champ->alive = TRUE;
	champ->id = id;
	if (get_header_body(fd, champ) == -1)
		fatal_exit_vm("invalid champion");
	ft_lst_push_back(g_vm.champs, (void*)champ);
	return (1);
}
