/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:06:14 by mbonowic          #+#    #+#             */
/*   Updated: 2016/07/18 18:06:17 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			param_type(char *param, t_lst *lst)
{
	if (!param)
		return (0);
	if (!check_register(param))
		return (1);
	if (!check_direct_4(param) || !check_direct_2(param, lst))
		return (2);
	if (!check_indirect(param, lst) || check_indirect(param, lst) == -1)
		return (3);
	return (0);
}

static int	parse_addr(char *label, t_lst *op)
{
	int				size;
	t_lst_elem__	*op_head;

	size = 0;
	op_head = op->head;
	while (op_head && ((((t_op *)(op_head->data))->type != LABEL) ||
				ft_strcmp(((t_op *)(op_head->data))->label, label)))
	{
		if (((t_op *)(op_head->data))->type == INSTR)
			size += ((t_op *)(op_head->data))->size;
		op_head = op_head->next;
	}
	return (size);
}

void		parser_label(t_lst *op, t_lst *token)
{
	t_lst_elem__	*op_head;
	t_lst_elem__	*token_head;

	op_head = op->head;
	token_head = token->head;
	while (op_head && token_head)
	{
		if (((t_op *)(op_head->data))->type == LABEL)
			((t_op *)(op_head->data))->size =
				parse_addr(((t_op *)(op_head->data))->label, op);
		op_head = op_head->next;
		token_head = token_head->next;
	}
}
