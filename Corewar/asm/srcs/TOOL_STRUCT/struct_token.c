/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:07:49 by mbonowic          #+#    #+#             */
/*   Updated: 2016/07/18 18:07:51 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

t_token		*token_new(void)
{
	return (ft_memalloc(sizeof(t_token)));
}

void		token_del(t_token *token)
{
	if (token->label)
		ft_strdel(&token->label);
	if (token->opcode)
		ft_strdel(&token->opcode);
	if (token->param1)
		ft_strdel(&token->param1);
	if (token->param2)
		ft_strdel(&token->param2);
	if (token->param3)
		ft_strdel(&token->param3);
	free(token);
}
