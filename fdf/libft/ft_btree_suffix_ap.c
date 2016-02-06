/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_suffix_ap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 23:15:03 by mbonowic          #+#    #+#             */
/*   Updated: 2015/11/27 23:15:15 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_suffix_ap(t_btree *root, void (*f)(void*))
{
	if (root != NULL)
	{
		ft_btree_suffix_ap(root->left, f);
		ft_btree_suffix_ap(root->right, f);
		f(root->content);
	}
}
