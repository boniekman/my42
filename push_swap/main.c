/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:45:12 by mbonowic          #+#    #+#             */
/*   Updated: 2016/03/02 08:49:26 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		end(t_list **a, t_list **b)
{
	write(2, "Error\n", 6);
	del_list(a);
	del_list(b);
	exit(2);
}

int			main(int argc, char **argv)
{
	t_all	all;
	int		i;

	all.a = NULL;
	all.b = NULL;
	i = 0;
	all.dec = 0;
	if (argc > 1)
	{
		if (ft_strcmp(argv[1], "-v") == 0)
		{
			all.dec = 1;
			i++;
		}
		else if (ft_strcmp(argv[1], "-w") == 0)
		{
			all.dec = 2;
			i++;
		}
		if ((all.a = parse(&argv[1 + i], &all.size)) == NULL)
			end(&all.a, &all.b);
		if (issorted(all.a) == 0)
			algo(&all);
	}
	return (0);
}
