/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:07:39 by mbonowic          #+#    #+#             */
/*   Updated: 2016/07/18 18:08:14 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

t_op		*op_new(void)
{
	int		i;
	t_op	*new;

	if (!(new = ft_memalloc(sizeof(t_op))))
		return (NULL);
	i = 0;
	while (i < 3)
	{
		new->param[i].size = 0;
		ft_memset(new->param[i].arr, 0, 4);
		i++;
	}
	return (new);
}

void		op_del(t_op *op)
{
	if (!op)
		return ;
	if (op->label)
		ft_strdel(&op->label);
	free(op);
}
