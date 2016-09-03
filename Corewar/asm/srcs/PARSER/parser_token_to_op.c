/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_token_to_op.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:06:28 by mbonowic          #+#    #+#             */
/*   Updated: 2016/07/18 18:07:05 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static char	get_ocp_from_token_2__(char *opcode)
{
	if (ft_strequ(opcode, "ldi"))
		return (10);
	else if (ft_strequ(opcode, "sti"))
		return (11);
	else if (ft_strequ(opcode, "fork"))
		return (12);
	else if (ft_strequ(opcode, "lld"))
		return (13);
	else if (ft_strequ(opcode, "lldi"))
		return (14);
	else if (ft_strequ(opcode, "lfork"))
		return (15);
	else if (ft_strequ(opcode, "aff"))
		return (16);
	return (-1);
}

static char	get_ocp_from_token_1__(char *opcode)
{
	if (ft_strequ(opcode, "live"))
		return (1);
	else if (ft_strequ(opcode, "ld"))
		return (2);
	else if (ft_strequ(opcode, "st"))
		return (3);
	else if (ft_strequ(opcode, "add"))
		return (4);
	else if (ft_strequ(opcode, "sub"))
		return (5);
	else if (ft_strequ(opcode, "and"))
		return (6);
	else if (ft_strequ(opcode, "or"))
		return (7);
	else if (ft_strequ(opcode, "xor"))
		return (8);
	else if (ft_strequ(opcode, "zjmp"))
		return (9);
	return (get_ocp_from_token_2__(opcode));
}

static void	token_to_op__(t_token *token, t_lst *op)
{
	t_op *new;

	new = op_new();
	new->type = token->type;
	if (token->type == LABEL)
		new->label = ft_strdup(token->label);
	else
		new->opcode = get_ocp_from_token_1__(token->opcode);
	ft_lst_push_back(op, (void*)new);
}

t_lst		*token_to_op(t_lst *token)
{
	t_lst *op;

	op = ft_lst_new();
	ft_lst_iter(token, (void(*)(void*, void*))token_to_op__, (void*)op);
	return (op);
}
