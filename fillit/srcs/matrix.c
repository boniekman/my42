/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:18:08 by ngrasset          #+#    #+#             */
/*   Updated: 2015/12/02 16:02:18 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_matrix	*create_matrix(t_controller *controller)
{
	t_matrix	*matrix;

	matrix = (t_matrix *)malloc(sizeof(t_matrix));
	if (!matrix)
		return (NULL);
	matrix->size = find_min_res_size(controller->input);
	matrix->data = create_square_strtab(matrix->size);
	if (!matrix->data)
	{
		free(matrix);
		return (NULL);
	}
	return (matrix);
}

void		grow_matrix(t_matrix *matrix)
{
	matrix->size++;
	delete_strtab(matrix->data);
	matrix->data = create_square_strtab(matrix->size);
}

void		delete_matrix(t_matrix *matrix)
{
	if (matrix->data)
		delete_strtab(matrix->data);
	free(matrix);
}
