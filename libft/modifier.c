/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 20:19:27 by mbonowic          #+#    #+#             */
/*   Updated: 2016/05/18 11:21:50 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	modifier_precedence(char *modifier)
{
	if (ft_strcmp(modifier, "ll") == 0)
		return (4);
	else if (ft_strcmp(modifier, "l") == 0 || ft_strcmp(modifier, "j") == 0
			|| ft_strcmp(modifier, "z") == 0)
		return (3);
	else if (ft_strcmp(modifier, "h") == 0)
		return (2);
	else
		return (1);
}

void		modifier(t_printf *ptr, char *modif)
{
	int ptr_mod;
	int new_mod;

	if (ptr->modifier == NULL)
		ptr->modifier = ft_strdup(modif);
	ptr_mod = modifier_precedence(ptr->modifier);
	new_mod = modifier_precedence(modif);
	if (new_mod > ptr_mod)
	{
		ft_strdel(&ptr->modifier);
		ptr->modifier = ft_strdup(modif);
	}
	ft_strdel(&modif);
}
