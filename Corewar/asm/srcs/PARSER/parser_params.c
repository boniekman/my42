/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:06:22 by mbonowic          #+#    #+#             */
/*   Updated: 2016/07/18 18:06:23 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int		ocp_inst(t_token *token, t_lst *lst)
{
	int param1;
	int param2;
	int param3;
	int ocp;

	param1 = param_type(token->param1, lst);
	param2 = param_type(token->param2, lst);
	param3 = param_type(token->param3, lst);
	ocp = 0;
	ocp |= param1 << 6;
	ocp |= param2 << 4;
	ocp |= param3 << 2;
	return (ocp);
}

static void		parser_ocp(t_op *op, t_token *token, t_lst *lst)
{
	if (op->opcode == 1 || op->opcode == 9 ||
		op->opcode == 12 || op->opcode == 15)
		return ;
	else
	{
		op->ocp = ocp_inst(token, lst);
		op->size += 1;
	}
}

static void		param_to_byte(char *param, t_lst *lst, t_param *par, int opcode)
{
	if (!check_register(param))
	{
		par->size = 1;
		par->arr[0] = ft_atoi(param + 1);
		par->arr[1] = 0;
		par->arr[2] = 0;
		par->arr[3] = 0;
	}
	else if (!check_direct_4(param) && !is_special_inst(opcode))
		par = four_bytes_param(param + 1, par);
	else if (!check_indirect(param, lst) ||
		(!check_direct_4(param) && is_special_inst(opcode)))
		par = two_bytes_param(param, par, 1, 0);
	else if (!check_direct_2(param, lst) || check_indirect(param, lst) == -1)
	{
		if (!check_direct_2(param, lst) && is_special_direct(opcode))
			par->size = 4;
		else
			par->size = 2;
	}
}

static void		parser_inst(t_op *op, t_token *token, t_lst *lst)
{
	if (token->param1)
		param_to_byte(token->param1, lst, &(op->param[0]), op->opcode);
	if (token->param2)
		param_to_byte(token->param2, lst, &(op->param[1]), op->opcode);
	if (token->param3)
		param_to_byte(token->param3, lst, &(op->param[2]), op->opcode);
	op->size = (op->param[0]).size +
		(op->param[1]).size + (op->param[2]).size + 1;
}

void			parser_params(t_lst *op, t_lst *token)
{
	t_lst_elem__	*op_head;
	t_lst_elem__	*token_head;
	int				addr;

	addr = 0;
	op_head = op->head;
	token_head = token->head;
	while (op_head && token_head)
	{
		if (((t_op *)(op_head->data))->type == 2)
		{
			parser_inst(((t_op *)(op_head->data)),
				((t_token *)(token_head->data)), token);
			parser_ocp(((t_op *)(op_head->data)),
				((t_token *)(token_head->data)), token);
			((t_op *)(op_head->data))->addr = addr;
			addr += ((t_op *)(op_head->data))->size;
		}
		op_head = op_head->next;
		token_head = token_head->next;
	}
}
