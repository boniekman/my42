/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 20:05:41 by mbonowic          #+#    #+#             */
/*   Updated: 2016/05/18 11:21:04 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_field_s(t_printf *ptr, char *str)
{
	int size;
	int length;
	int to_print;

	size = 0;
	length = ft_strlen(str);
	if (ptr->is_zero)
		size = ptr->nbr_zero;
	if (ptr->is_preci && ptr->nbr_preci < length)
		length = ptr->nbr_preci;
	to_print = (size > length) ? size : length;
	if (ptr->is_plus)
		to_print++;
	while (ptr->nbr_field > to_print)
	{
		ptr->print += ft_putchar(' ');
		ptr->nbr_field--;
	}
}

static void	print_flag_s(t_printf *ptr, char *str)
{
	int size;
	int length;

	size = 0;
	length = ft_strlen(str);
	if (ptr->is_zero)
		size = ptr->nbr_zero;
	if (ptr->is_preci && ptr->nbr_preci < length)
		length = ptr->nbr_preci;
	while (size > length)
	{
		ptr->print += ft_putchar('0');
		size--;
	}
}

static void	printfstr(t_printf *ptr, char *str)
{
	unsigned int	i;

	i = 0;
	if (str == NULL)
	{
		if (ptr->is_zero == 0)
			ptr->print += ft_putstr("(null)");
		else
			while ((int)--ptr->nbr_zero >= 0)
				ptr->print += ft_putchar('0');
		return ;
	}
	print_field_s(ptr, str);
	print_flag_s(ptr, str);
	if (ptr->is_preci == 0)
		ptr->print += ft_putstr(str);
	else
	{
		while (str[i] && (int)i < ptr->nbr_preci)
		{
			ptr->print += write(1, &str[i], 1);
			i++;
		}
	}
	pad_after(ptr, ptr->print);
}

void		handler_cs(t_printf *ptr, va_list ap)
{
	if (ptr->conversion == 's' && ptr->modifier == NULL)
		printfstr(ptr, va_arg(ap, char*));
	else if (ptr->conversion == 'S' || ptr->conversion == 's')
		printfwstr(ptr, va_arg(ap, wchar_t*));
	else if (ptr->conversion == 'c' || ptr->conversion == 'C')
	{
		print_field_c(ptr);
		print_flag_c(ptr);
		if (ptr->conversion == 'c' && ptr->modifier == NULL)
			ptr->print += ft_putchar((char)va_arg(ap, int));
		else
			ptr->print += ft_putwchar(va_arg(ap, wchar_t));
		pad_after(ptr, 1);
	}
}
