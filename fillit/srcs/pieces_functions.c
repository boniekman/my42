/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:12:20 by ngrasset          #+#    #+#             */
/*   Updated: 2015/12/02 12:35:56 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	*new_piece(char **data, int index)
{
	t_piece	*new_piece;

	new_piece = (t_piece *)malloc(sizeof(t_piece));
	if (!new_piece)
		return (NULL);
	new_piece->letter = (char)index + 'A';
	new_piece->data = data;
	new_piece->width = find_piece_width(data);
	new_piece->height = find_piece_height(data);
	find_piece_offset(data, &(new_piece->off_x), &(new_piece->off_y));
	new_piece->next = NULL;
	return (new_piece);
}

void	push_piece_back(t_piece **head, t_piece *new)
{
	t_piece	*cur;

	if (!new)
		return ;
	if (!head)
		return ;
	cur = *head;
	if (!cur)
	{
		*head = new;
		return ;
	}
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

void	delete_list(t_piece *head)
{
	t_piece	*next;

	while (head)
	{
		next = head->next;
		if (head->data)
			delete_strtab(head->data);
		free(head);
		head = next;
	}
}

int		find_min_res_size(t_piece *head)
{
	int		count;
	int		size;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	count *= 4;
	size = 1;
	while (size * size < count)
		size += 1;
	return (size);
}
