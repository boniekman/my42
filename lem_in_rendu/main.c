/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:32:36 by mbonowic          #+#    #+#             */
/*   Updated: 2016/03/17 11:29:04 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(void)
{
	t_all	all;
	char	*error;

	error = NULL;
	if (init(&all, &error) == -1)
		ft_putendl(error);
	else if (algo(&all, &error) == -1)
		ft_putendl(error);
	/*ft_putstr("S : ");
	ft_putnbr(all.start);
	ft_putendl("");
	ft_putstr("E : ");
	ft_putnbr(all.end);
	ft_putendl("");*/
	print_list(all.room);
	print_cons(all);
	print_weights(all);
	/*print_arr(all);*/
	return (0);
}
