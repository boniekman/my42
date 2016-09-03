/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 13:38:16 by akpenou           #+#    #+#             */
/*   Updated: 2016/07/18 16:05:09 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

unsigned int	reverse_byte(unsigned int number)
{
	unsigned int	num;
	char			tmp;

	num = 0;
	tmp = ((number << 24) >> 24);
	num |= (tmp << 24);
	tmp = (((number >> 8) << 24) >> 24);
	num |= (tmp << 16);
	tmp = (((number >> 16) << 24) >> 24);
	num |= (tmp << 8);
	tmp = (((number >> 24) << 24) >> 24);
	num |= tmp;
	return (num);
}

static bool		iter_id__(t_champ *champ, unsigned int *id)
{
	return (champ->id == *id);
}

int				is_free_id(int id)
{
	return ((ft_lst_find(g_vm.champs, (bool(*)(void*, void*))iter_id__, &id))
			? false : true);
}

static void		set_id__(t_champ *champ, unsigned int *id)
{
	if (champ->id != 0)
		return ;
	while (!is_free_id(*id))
		(*id)++;
	champ->id = (*id)++;
}

void			set_remaining_id(void)
{
	unsigned int id;

	id = 1;
	ft_lst_iter(g_vm.champs, (void(*)(void*, void*))set_id__, &id);
}
