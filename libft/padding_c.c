/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 20:22:09 by mbonowic          #+#    #+#             */
/*   Updated: 2016/05/18 11:17:03 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_field_c(t_printf *ptr)
{
	unsigned int	size;

	if (ptr->is_minus)
		return ;
	size = 1;
	if (ptr->is_zero)
		size += ptr->nbr_zero;
	while (ptr->nbr_field > (int)size)
	{
		ptr->print += ft_putchar(' ');
		ptr->nbr_field--;
	}
}

void	print_flag_c(t_printf *ptr)
{
	unsigned int size;

	size = 0;
	if (ptr->is_zero)
		size += ptr->nbr_zero;
	while (size > 1)
	{
		ptr->print += ft_putchar('0');
		size--;
	}
}
