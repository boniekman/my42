/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:00:24 by mbonowic          #+#    #+#             */
/*   Updated: 2016/07/18 18:00:26 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int	check_inst(t_token *token, t_lst *lst)
{
	if (!ft_strcmp(token->opcode, "live"))
		return (check_live(token, lst));
	if (!ft_strcmp(token->opcode, "ld") || !ft_strcmp(token->opcode, "lld"))
		return (check_ld(token, lst));
	if (!ft_strcmp(token->opcode, "st"))
		return (check_st(token, lst));
	if (!ft_strcmp(token->opcode, "add") || !ft_strcmp(token->opcode, "sub"))
		return (check_add_sub(token));
	if (!ft_strcmp(token->opcode, "and") || !ft_strcmp(token->opcode, "or")
		|| !ft_strcmp(token->opcode, "xor"))
		return (check_logical(token, lst));
	if (!ft_strcmp(token->opcode, "zjmp"))
		return (check_zjmp(token, lst));
	if (!ft_strcmp(token->opcode, "ldi") || !ft_strcmp(token->opcode, "lldi"))
		return (check_ldi(token, lst));
	if (!ft_strcmp(token->opcode, "sti"))
		return (check_sti(token, lst));
	if (!ft_strcmp(token->opcode, "fork") || !ft_strcmp(token->opcode, "lfork"))
		return (check_fork(token, lst));
	if (!ft_strcmp(token->opcode, "aff"))
		return (check_aff(token));
	ft_putstr_fd("Unknown instruction <", 2);
	ft_putstr_fd(token->opcode, 2);
	ft_putstr_fd(">\n", 2);
	return (0);
}

static int	check_label(char *label, t_lst *head)
{
	t_lst_elem__	*token;
	int				duplicate;

	duplicate = -1;
	token = head->head;
	while (token)
	{
		if (!((t_token *)(token->data))->label)
		{
			token = token->next;
			continue ;
		}
		if (!ft_strcmp(((t_token *)(token->data))->label, label))
			duplicate++;
		token = token->next;
	}
	if (duplicate != 0)
	{
		ft_putstr_fd("Duplicate label <", 2);
		ft_putstr_fd(label, 2);
		ft_putstr_fd(">\n", 2);
	}
	return (duplicate);
}

int			check_errors(t_lst *lst)
{
	t_lst_elem__	*token;

	token = lst->head;
	while (token)
	{
		if (((t_token *)(token->data))->type == 1)
			if (check_label(((t_token *)(token->data))->label, lst))
				return (1);
		if (((t_token *)(token->data))->type == 2)
			if (check_inst((t_token *)(token->data), lst))
				return (1);
		token = token->next;
	}
	return (0);
}
