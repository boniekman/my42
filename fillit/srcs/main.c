/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:41:42 by ngrasset          #+#    #+#             */
/*   Updated: 2015/12/02 16:01:10 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		main(int argc, char **argv)
{
	t_controller	*controller;

	if (argc != 2)
		fatal();
	controller = create_controller();
	if (!controller)
		fatal();
	open_file(argv[1], controller);
	controller->val_max = find_piece_max_index(controller->input);
	controller->matrix = create_matrix(controller);
	if (!controller->matrix)
		fatal_free_controller(controller);
	while (!place_pieces_recur(controller, controller->input))
		grow_matrix(controller->matrix);
	ft_putstrtab(controller->matrix->data);
	delete_controller(controller);
}

void	fatal(void)
{
	ft_putendl("error");
	exit(0);
}

void	fatal_free_controller(t_controller *controller)
{
	delete_controller(controller);
	ft_putendl("error");
	exit(0);
}
