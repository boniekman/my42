/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 23:15:39 by mbonowic          #+#    #+#             */
/*   Updated: 2015/11/27 23:20:33 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bt_ins(t_btree **r, t_btree *e, int (*f)(void*, void*))
{
	int		flag;

	flag = 1;
	if ((*r) == NULL)
	{
		*r = e;
		flag = 0;
	}
	if (f((*r)->content, e->content) < 0 && flag)
	{
		ft_bt_ins(&((*r)->right), e, f);
	}
	if (f((*r)->content, e->content) > 0 && flag)
	{
		ft_bt_ins(&((*r)->left), e, f);
	}
}
