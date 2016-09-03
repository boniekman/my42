/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 21:13:28 by mbonowic          #+#    #+#             */
/*   Updated: 2016/05/18 11:22:39 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	controller_invalid(t_printf *ptr)
{
	print_field_c(ptr);
	print_flag_c(ptr);
	if (ptr->conversion != 0)
		ptr->print += ft_putchar(ptr->conversion);
	pad_after(ptr, 1);
}

static void	conversion_controller(t_printf *ptr, va_list ap)
{
	char ch;

	ch = ptr->conversion;
	if (ch == 'c' || ch == 'C' || ch == 's' || ch == 'S')
		handler_cs(ptr, ap);
	else if (ch == 'p' || ch == 'x' || ch == 'X')
		handler_xp(ptr, ap);
	else if (ch == 'd' || ch == 'D' || ch == 'i')
		handler_di(ptr, ap);
	else if (ch == 'o' || ch == 'O')
		handler_o(ptr, ap);
	else if (ch == 'u' || ch == 'U')
		handler_u(ptr, ap);
	else if (ch == 'b')
		handler_b(ptr, ap);
	else if (ch == 'k')
		recu_print_time(va_arg(ap, unsigned long long int), 1, ptr);
	else if (ch == 'a' || ch == 'A')
		handler_a(ptr, ap);
	else
		controller_invalid(ptr);
}

static int	is_precision(char ch)
{
	if (ch == '.' || ch == '*' || ft_isdigit(ch))
		return (1);
	return (0);
}

void		pad_after(t_printf *ptr, int length)
{
	int size;

	size = 0;
	if (ptr->is_minus)
		size = ptr->nbr_minus;
	while (size > length)
	{
		ptr->print += ft_putchar(' ');
		size--;
	}
}

void		instruction(t_printf *ptr, va_list ap)
{
	int		i;
	int		length;
	char	*temp;

	i = 0;
	while (ptr->instr[i])
	{
		if (is_flag(ptr->instr + i))
			i += flag_control(ptr, i);
		else if ((length = is_modifier(ptr->instr + i)))
		{
			temp = ft_strsub(ptr->instr, i, length);
			modifier(ptr, temp);
			i += (length == 2) ? i + 1 : i;
		}
		else if (is_precision(ptr->instr[i]))
			i += preci_field(ptr, i, ap);
		i++;
	}
	if (ptr->is_minus && ptr->is_field)
	{
		ptr->nbr_minus = ptr->nbr_field;
		ptr->nbr_field = 0;
	}
	conversion_controller(ptr, ap);
}
