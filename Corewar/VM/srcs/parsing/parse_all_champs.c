/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_all_champs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 13:38:03 by akpenou           #+#    #+#             */
/*   Updated: 2016/07/18 13:38:10 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		get_dump(int index, int ac, char **av)
{
	if (index + 1 >= ac || !ft_isnumber(av[index + 1]))
		fatal_exit_vm("invalid number provided to -dump option");
	if (g_vm.dump != -2)
		fatal_exit_vm("conflicting dump imformation provided");
	if ((g_vm.dump = ft_atoi(av[index + 1])) < 0)
		fatal_exit_vm("dump number must be positive");
	return (2);
}

static int		get_champ_with_id(int index, int ac, char **av)
{
	if (index + 2 >= ac || !ft_isnumber(av[index + 1]) ||
			!is_free_id(ft_atoi(av[index + 1]))
			|| ft_atoi(av[index + 1]) <= 0)
		fatal_exit_vm("invalid id provided to -n option, id > 0 and unique");
	return (parse_champ(av[index + 2], ft_atoi(av[index + 1])) + 2);
}

static int		process_next_argument(int index, int ac, char **av)
{
	if (ft_strcmp(av[index], "-dump") == 0)
		return (get_dump(index, ac, av));
	else if (ft_strcmp(av[index], "-n") == 0)
		return (get_champ_with_id(index, ac, av));
	else if (ft_strcmp(av[index], "-v") == 0)
		return (ft_initncurses());
	else
		return (parse_champ(av[index], 0));
}

int				parse_all_champs(int ac, char **av)
{
	int			index;

	index = 1;
	while (index < ac)
		index += process_next_argument(index, ac, av);
	if (ft_lst_len(g_vm.champs) > MAX_PLAYERS)
		fatal_exit_vm("too much champions provided, limit is 4");
	if (ft_lst_len(g_vm.champs) == 0)
		fatal_exit_vm("at least one champion is required to launch the VM");
	set_remaining_id();
	put_in_ram();
	return (TRUE);
}
