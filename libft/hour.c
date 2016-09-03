/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hour.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 20:16:42 by mbonowic          #+#    #+#             */
/*   Updated: 2016/05/18 11:22:53 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recu_print_time2(unsigned long int time, int index, t_printf *ptr)
{
	if (time == 0)
		return ;
	if (index == 1)
	{
		recu_print_time2(time / 7, 2, ptr);
		ptr->print += ft_printf("%02dD ", time % 7);
	}
	else if (index == 2)
	{
		recu_print_time2(time / 52, 3, ptr);
		ptr->print += ft_printf("%02dW-", time % 52);
	}
	else if (index == 3)
		ptr->print += ft_printf("%3dY-", time);
}

void		recu_print_time(unsigned long int time, int index, t_printf *ptr)
{
	if (index == 1)
	{
		recu_print_time(time / 60, 2, ptr);
		ptr->print += ft_printf("%02d", time % 60);
	}
	else if (index == 2)
	{
		recu_print_time(time / 60, 3, ptr);
		ptr->print += ft_printf("%02d:", time % 60);
	}
	else if (index == 3)
	{
		recu_print_time2(time / 24, 1, ptr);
		ptr->print += ft_printf("T%02d:", time % 24);
	}
}
