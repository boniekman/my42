/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 21:25:41 by mbonowic          #+#    #+#             */
/*   Updated: 2016/05/18 11:20:38 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_field_b(t_printf *ptr, char *number, unsigned long long nbr)
{
	int size;
	int length;
	int to_print;

	if (ptr->is_minus)
		return ;
	size = 0;
	length = ft_strlen(number);
	if (ptr->is_zero && ptr->is_minus == 0 && ptr->is_preci == 0)
		size = ptr->nbr_zero;
	else if (ptr->is_preci && ptr->nbr_preci)
		size = ptr->nbr_preci;
	to_print = (size > length) ? size : length;
	if (ptr->is_plus)
		to_print++;
	if (nbr == 0 && ptr->is_preci && ptr->nbr_preci == 0)
		to_print -= 1;
	while (ptr->nbr_field > to_print)
	{
		ptr->print += ft_putchar(' ');
		ptr->nbr_field--;
	}
}

static void	print_flag_b(t_printf *ptr, char *number, unsigned long long nbr)
{
	int size;
	int length;

	if (nbr)
		size = 0;
	size = 0;
	length = ft_strlen(number);
	if (ptr->is_zero && ptr->is_minus == 0 && ptr->is_preci == 0)
		size = ptr->nbr_zero;
	else if (ptr->is_preci && ptr->nbr_preci)
		size = ptr->nbr_preci;
	while (size > length)
	{
		ptr->print += ft_putchar('0');
		size--;
	}
}

static int	print_b(unsigned long long int nbr, t_printf *ptr)
{
	int		length;
	char	*number;
	int		total_length;

	number = ft_uitoa_base(nbr, 2);
	if (number == NULL)
	{
		ptr->print = -1;
		return (-1);
	}
	length = ft_strlen(number);
	print_field_b(ptr, number, nbr);
	print_flag_b(ptr, number, nbr);
	if (!(ptr->is_preci && ptr->nbr_preci == 0 && nbr == 0))
		ptr->print += ft_putstr(number);
	total_length = ptr->print;
	pad_after(ptr, total_length);
	ft_strdel(&number);
	return (length);
}

void		handler_b(t_printf *ptr, va_list ap)
{
	if (ptr->modifier == NULL)
		print_b(va_arg(ap, unsigned int), ptr);
	else if (ft_strcmp(ptr->modifier, "l") == 0)
		print_b(va_arg(ap, unsigned long int), ptr);
	else if (ft_strcmp(ptr->modifier, "ll") == 0)
		print_b(va_arg(ap, unsigned long long int), ptr);
	else if (ft_strcmp(ptr->modifier, "h") == 0)
		print_b((unsigned short)va_arg(ap, int), ptr);
	else if (ft_strcmp(ptr->modifier, "hh") == 0)
		print_b((unsigned char)va_arg(ap, int), ptr);
	else if (ft_strcmp(ptr->modifier, "j") == 0)
		print_b(va_arg(ap, uintmax_t), ptr);
	else if (ft_strcmp(ptr->modifier, "z") == 0)
		print_b(va_arg(ap, size_t), ptr);
}
