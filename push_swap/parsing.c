/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 18:55:14 by mbonowic          #+#    #+#             */
/*   Updated: 2016/03/02 09:20:24 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_int(char *s, int i)
{
	if (s[0] == '-')
	{
		i = 1;
		while (s[i])
		{
			if (ft_isdigit(s[i]) == 0)
				return (-1);
			i++;
		}
		if (ft_latoi(s) < -2147483648)
			return (-1);
	}
	else
	{
		while (s[i])
		{
			if (ft_isdigit(s[i]) == 0)
				return (-1);
			i++;
		}
		if (ft_latoi(s) > 2147483647)
			return (-1);
	}
	return (1);
}

t_list		*parse(char **argv, int *size)
{
	t_list	*list;
	int		i;
	int		max;

	list = NULL;
	i = 0;
	while (argv[i] != NULL)
	{
		if (is_int(argv[i], 0) == -1)
			return (NULL);
		if (add_elem(&list, create_new(ft_atoi(argv[i]))) == -1)
			return (NULL);
		i++;
	}
	*size = i;
	return (list);
}
