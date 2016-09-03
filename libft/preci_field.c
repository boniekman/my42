/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preci_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 20:24:49 by mbonowic          #+#    #+#             */
/*   Updated: 2016/05/18 11:22:19 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_field(t_printf *ptr, va_list ap, int index)
{
	int i;

	i = 0;
	ptr->is_field = 1;
	if (ptr->instr[index] == '*')
	{
		ptr->nbr_field = va_arg(ap, int);
		if (ptr->nbr_field < 0)
		{
			ptr->is_minus = 1;
			ptr->nbr_minus = -ptr->nbr_field;
			ptr->nbr_field = 0;
			ptr->is_field = 0;
		}
	}
	else
	{
		ptr->nbr_field = ft_atoi(ptr->instr + index);
		while (ptr->instr[index + i + 1] &&
				ft_isdigit(ptr->instr[index + i + 1]))
			i++;
	}
	return (i);
}

static int	get_preci(t_printf *ptr, int index, va_list ap)
{
	int i;

	i = 0;
	ptr->is_preci = 1;
	if (ptr->instr[index + 1] == '*')
	{
		ptr->nbr_preci = va_arg(ap, int);
		if (ptr->nbr_preci < 0)
			ptr->is_preci = 0;
		++i;
	}
	else
	{
		ptr->nbr_preci = ft_atoi(ptr->instr + index + 1);
		while (ptr->instr[index + i + 1] &&
				ft_isdigit(ptr->instr[index + i + 1]))
			i++;
	}
	return (i);
}

int			preci_field(t_printf *ptr, int index, va_list ap)
{
	if (ptr->instr[index] == '*' || ft_isdigit(ptr->instr[index]))
		return (get_field(ptr, ap, index));
	else if (ptr->instr[index] == '.')
		return (get_preci(ptr, index, ap));
	return (0);
}
