/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 20:00:51 by mbonowic          #+#    #+#             */
/*   Updated: 2016/05/18 11:23:12 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_flag(char *str)
{
	if (*str == '#' || *str == '-' || *str == '+' || *str == ' ')
		return (1);
	else if (*str == '0' && !ft_isdigit(*(str - 1)))
		return (1);
	return (0);
}

int		is_modifier(char *instr)
{
	if (*instr == 'l' && (*(instr + 1) == 'l' && *(instr + 2) != 'l'))
		return (2);
	else if (*instr == 'l')
		return (1);
	else if (*instr == 'h' && (*(instr + 1) == 'h' && *(instr + 2) != 'h'))
		return (2);
	else if (*instr == 'h')
		return (1);
	else if (*instr == 'j' && *(instr + 1) != 'j')
		return (1);
	else if (*instr == 'z' && *(instr + 1) != 'z')
		return (1);
	return (0);
}

int		is_preci(char *inst)
{
	int i;

	i = 0;
	if (inst[i] != '.')
		return (0);
	else
		i++;
	if (inst[i] == '*')
		return (2);
	else
	{
		while (inst[i] && ft_isdigit(inst[i]))
			i++;
		return (i);
	}
}
