/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_champ_by_id.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 15:34:11 by akpenou           #+#    #+#             */
/*   Updated: 2016/07/18 15:34:13 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static bool	find_by_no__(void *data, void *no)
{
	t_champ	*champ;
	int		*champ_no;

	champ = data;
	champ_no = no;
	return (champ->no == *champ_no);
}

static bool	find_by_id__(void *data, void *id)
{
	t_champ				*champ;
	unsigned int		*champ_id;

	champ = data;
	champ_id = id;
	return (champ->id == *champ_id);
}

t_champ		*get_champ_by_no(unsigned int no)
{
	return (ft_lst_find(g_vm.champs, find_by_no__, &no));
}

t_champ		*get_champ_by_id(unsigned int id)
{
	return (ft_lst_find(g_vm.champs, find_by_id__, &id));
}
