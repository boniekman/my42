/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:15:07 by ngrasset          #+#    #+#             */
/*   Updated: 2015/12/02 14:19:30 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

t_controller	*create_controller(void)
{
	t_controller	*ret;

	ret = (t_controller *)malloc(sizeof(t_controller));
	if (!ret)
		return (NULL);
	ret->input = NULL;
	ret->matrix = NULL;
	ret->val_max = 0;
	return (ret);
}

void			delete_controller(t_controller *controller)
{
	if (!controller)
		return ;
	if (controller->input)
		delete_list(controller->input);
	if (controller->matrix)
		delete_matrix(controller->matrix);
	free(controller);
}
