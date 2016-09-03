/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:05:19 by ngrasset          #+#    #+#             */
/*   Updated: 2015/12/18 14:27:34 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void		open_file(char const *file_name, t_controller *controller)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		fatal_free_controller(controller);
	parse_file(fd, controller);
	close(fd);
}

void		parse_file(int fd, t_controller *controller)
{
	char	buffer[BUF_SIZE + 1];
	char	**square;
	int		ret;
	int		count;
	char	last_char;

	count = 0;
	while ((ret = read(fd, buffer, BUF_SIZE)))
	{
		if (ret != BUF_SIZE)
			fatal_free_controller(controller);
		buffer[BUF_SIZE] = '\0';
		if (buffer[BUF_SIZE - 1] != '\n'
				|| !(square = ft_strsplit(buffer, '\n')))
			fatal_free_controller(controller);
		if (!check_square(square))
			fatal_free_controller(controller);
		push_piece_back(&(controller->input), new_piece(square, count));
		count++;
		last_char = ft_getchar(fd);
		if (last_char != '\n' && last_char != -1)
			fatal_free_controller(controller);
	}
	if (count < 1 || count > 26 || last_char != -1)
		fatal_free_controller(controller);
}

static void	init_norme(int *tab)
{
	tab[0] = -1;
	tab[1] = -1;
	tab[2] = 4;
	tab[3] = 0;
}

int			check_square(char **square)
{
	int		n[4];

	init_norme(n);
	while (square[++n[0]])
	{
		while (square[n[0]][++n[1]] != '\0')
		{
			if (square[n[0]][n[1]] != '.' && square[n[0]][n[1]] != '#')
				return (0);
			if (square[n[0]][n[1]] == '#')
			{
				check_block_contact(square, n[0], n[1], &n[3]);
				n[2]--;
			}
		}
		if (n[1] != 4)
			return (0);
		n[1] = -1;
	}
	if (n[0] != 4 || n[2] != 0 || n[3] < 6)
		return (0);
	return (1);
}

void		check_block_contact(char **square, int i, int j, int *contact)
{
	if (j > 0 && square[i][j - 1] == '#')
		(*contact)++;
	if (j < 3 && square[i][j + 1] == '#')
		(*contact)++;
	if (i > 0 && square[i - 1][j] == '#')
		(*contact)++;
	if (i < 3 && square[i + 1][j] == '#')
		(*contact)++;
}
