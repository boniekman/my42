/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_infix_ap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 23:14:05 by mbonowic          #+#    #+#             */
/*   Updated: 2015/11/27 23:14:19 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_infix_ap(t_btree *root, void (*f)(void*))
{
	if (root != NULL)
	{
		ft_btree_infix_ap(root->left, f);
		f(root->content);
		ft_btree_infix_ap(root->right, f);
	}
}
