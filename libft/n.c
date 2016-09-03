/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 21:17:23 by mbonowic          #+#    #+#             */
/*   Updated: 2016/05/18 11:20:14 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handler_n(t_printf *ptr, va_list ap, int count)
{
	int		*tab;
	long	*tab2;
	short	*tab3;

	if (ptr->modifier == NULL)
	{
		tab = va_arg(ap, int*);
		*tab = count;
	}
	else if (ptr->modifier[0] == 'l')
	{
		tab2 = va_arg(ap, long*);
		*tab2 = (long)count;
	}
	else if (ptr->modifier[0] == 'h')
	{
		tab3 = va_arg(ap, short*);
		*tab3 = (short)count;
	}
}
