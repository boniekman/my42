/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_prefix_ap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 23:14:38 by mbonowic          #+#    #+#             */
/*   Updated: 2015/11/27 23:14:49 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_prefix_ap(t_btree *root, void (*f)(void*))
{
	if (root != NULL)
	{
		f(root->content);
		ft_btree_prefix_ap(root->left, f);
		ft_btree_prefix_ap(root->right, f);
	}
}
