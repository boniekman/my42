/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_del_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 23:12:44 by mbonowic          #+#    #+#             */
/*   Updated: 2015/11/27 23:12:53 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_del_node(t_btree **r)
{
	if ((*r)->content != NULL)
		free((*r)->content);
	free(*r);
	*r = NULL;
}
