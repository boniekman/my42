/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:06:08 by mbonowic          #+#    #+#             */
/*   Updated: 2016/07/18 18:06:09 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int			find_addr(t_lst *head, char *param)
{
	t_lst_elem__	*op_head;
	char			*tmp;

	tmp = (param[0] == '%') ? ft_strjoin(param + 2, ":") :
		ft_strjoin(param + 1, ":");
	op_head = head->head;
	while (op_head && (((t_op *)(op_head->data))->type == INSTR ||
		ft_strcmp(tmp, ((t_op *)(op_head->data))->label)))
		op_head = op_head->next;
	ft_strdel(&tmp);
	return (((t_op *)(op_head->data))->size);
}

static t_param		*ptba(char *param,
	t_op *op, t_lst *head, int mode)
{
	int		nbr;
	char	*addr;
	t_param	par;
	t_param *tmp;

	tmp = &par;
	nbr = find_addr(head, param) - op->addr;
	addr = ft_itoa(nbr);
	tmp = two_bytes_param(addr, tmp, 0, mode);
	ft_strdel(&addr);
	return (tmp);
}

static void			parser_inst_addr(t_op *op,
	t_token *t, t_lst *lst, t_lst *h)
{
	if (t->param1 && (!check_direct_2(t->param1, lst) ||
		check_indirect(t->param1, lst) == -1))
	{
		if (is_special_direct(op->opcode))
			ft_memcpy(op->param[0].arr, (ptba(t->param1, op, h, 1))->arr, 4);
		else
			ft_memcpy(op->param[0].arr, (ptba(t->param1, op, h, 0))->arr, 4);
	}
	if (t->param2 && (!check_direct_2(t->param2, lst) ||
		check_indirect(t->param2, lst) == -1))
	{
		if (is_special_direct(op->opcode))
			ft_memcpy(op->param[1].arr, (ptba(t->param2, op, h, 1))->arr, 4);
		else
			ft_memcpy(op->param[1].arr, (ptba(t->param2, op, h, 0))->arr, 4);
	}
	if (t->param3 && (!check_direct_2(t->param3, lst) ||
		check_indirect(t->param3, lst) == -1))
	{
		if (is_special_direct(op->opcode))
			ft_memcpy(op->param[2].arr, (ptba(t->param3, op, h, 1))->arr, 4);
		else
			ft_memcpy(op->param[2].arr, (ptba(t->param3, op, h, 0))->arr, 4);
	}
}

void				parser_addr(t_lst *op, t_lst *token)
{
	t_lst_elem__ *op_head;
	t_lst_elem__ *token_head;

	op_head = op->head;
	token_head = token->head;
	while (op_head && token_head)
	{
		if (((t_op *)(op_head->data))->type == 2)
			parser_inst_addr(((t_op *)(op_head->data)),
			((t_token *)(token_head->data)), token, op);
		op_head = op_head->next;
		token_head = token_head->next;
	}
}
