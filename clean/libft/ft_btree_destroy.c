/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 23:13:06 by mbonowic          #+#    #+#             */
/*   Updated: 2015/11/27 23:13:28 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_destroy(t_btree **root)
{
	if (*root != NULL)
	{
		ft_btree_destroy(&((*root)->left));
		ft_btree_destroy(&((*root)->right));
		ft_btree_del_node(root);
	}
}
