/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:08:07 by ngrasset          #+#    #+#             */
/*   Updated: 2015/12/02 16:05:13 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		place_pieces_recur(t_controller *ctr, t_piece *current)
{
	int		i;
	int		j;

	i = 0;
	while (i + current->height <= ctr->matrix->size)
	{
		j = 0;
		while (j + current->width <= ctr->matrix->size)
		{
			if (is_piece_placeable(ctr->matrix, current, i, j))
			{
				put_piece(ctr->matrix->data, current, i, j);
				if (!current->next)
					return (1);
				if (!place_pieces_recur(ctr, current->next))
					remove_letter(ctr->matrix->data, current->letter);
				else
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	put_piece(char **tab, t_piece *piece, int line, int column)
{
	int		i;
	int		j;
	int		w_column;

	i = piece->off_x;
	w_column = column;
	while (i < 4)
	{
		j = piece->off_y;
		while (j < 4)
		{
			if (piece->data[i][j] == '#')
				tab[line][w_column] = piece->letter;
			j++;
			w_column++;
		}
		w_column = column;
		i++;
		line++;
	}
}

int		is_piece_placeable(t_matrix *matrix, t_piece *piece, int l, int c)
{
	int		i;
	int		j;
	int		m_i;
	int		m_j;

	i = piece->off_x;
	while (i < 4)
	{
		j = piece->off_y;
		while (j < 4)
		{
			m_i = l + i - piece->off_x;
			m_j = c + j - piece->off_y;
			if (piece->data[i][j] == '#' &&
					matrix->data[m_i][m_j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
