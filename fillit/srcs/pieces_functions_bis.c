/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces_functions_bis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:50:47 by ngrasset          #+#    #+#             */
/*   Updated: 2015/12/02 10:51:20 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		find_piece_width(char **data)
{
	int		width;
	int		i;
	int		j;

	if (!data)
		return (0);
	j = 0;
	width = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (data[i][j] == '#')
			{
				width++;
				break ;
			}
			i++;
		}
		j++;
	}
	return (width);
}

int		find_piece_height(char **data)
{
	int		height;
	int		i;
	int		j;

	if (!data)
		return (0);
	i = 0;
	height = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (data[i][j] == '#')
			{
				height++;
				break ;
			}
			j++;
		}
		i++;
	}
	return (height);
}

void	find_piece_offset(char **data, int *off_x, int *off_y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!data)
		return ;
	while (is_line_empty(data, i))
		i++;
	while (is_column_empty(data, j))
		j++;
	*off_x = i;
	*off_y = j;
}

char	find_piece_max_index(t_piece *head)
{
	char	index;

	index = 'A';
	while (head)
	{
		index = head->letter;
		head = head->next;
	}
	return (index);
}
