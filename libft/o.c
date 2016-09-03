/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 21:17:33 by mbonowic          #+#    #+#             */
/*   Updated: 2016/05/18 11:21:33 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_field_o(t_printf *ptr, char *number, unsigned long long nbr)
{
	int size;
	int length;
	int to_print;

	if (ptr->is_minus)
		return ;
	size = 0;
	length = ft_strlen(number);
	if (ptr->is_hash && ptr->conversion == 'o' && nbr != 0)
		length++;
	else if (ptr->is_hash && ptr->conversion == 'O' && nbr != 0)
		length++;
	if (ptr->is_zero && ptr->is_minus == 0 && ptr->is_preci == 0)
		size = ptr->nbr_zero;
	else if (ptr->is_preci && ptr->nbr_preci)
		size = ptr->nbr_preci;
	to_print = (size > length) ? size : length;
	if (ptr->is_plus)
		to_print++;
	if (nbr == 0 && ptr->is_preci && ptr->nbr_preci == 0)
		to_print -= 1;
	while (ptr->nbr_field >= ++to_print)
		ptr->print += ft_putchar(' ');
}

static void	print_flag_o(t_printf *ptr, char *number, unsigned long long nbr)
{
	int size;
	int length;

	size = 0;
	length = ft_strlen(number);
	if (ptr->is_hash && nbr != 0)
		ptr->print += ft_putchar('0');
	else if (ptr->is_hash && ptr->is_preci && nbr == 0)
		ptr->print += ft_putchar('0');
	if (ptr->is_hash)
		length += 1;
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

static int	print_o(unsigned long long int nbr, t_printf *ptr)
{
	int		length;
	char	*number;
	int		total_length;

	length = 0;
	if (ptr->is_hash && nbr != 0)
		length += 1;
	if ((number = ft_uitoa_base(nbr, 8)) == NULL)
	{
		ptr->print = -1;
		return (-1);
	}
	length += ft_strlen(number);
	print_field_o(ptr, number, nbr);
	print_flag_o(ptr, number, nbr);
	if (!(ptr->is_preci && ptr->nbr_preci == 0 && nbr == 0))
		ptr->print += ft_putstr(number);
	total_length = ptr->print;
	pad_after(ptr, total_length);
	ft_strdel(&number);
	return (length);
}

void		handler_o(t_printf *ptr, va_list ap)
{
	if (ptr->modifier == NULL && ptr->conversion != 'O')
		print_o(va_arg(ap, unsigned int), ptr);
	else if (ptr->conversion == 'O' || ft_strcmp(ptr->modifier, "l") == 0)
		print_o(va_arg(ap, unsigned long int), ptr);
	else if (ft_strcmp(ptr->modifier, "ll") == 0)
		print_o(va_arg(ap, unsigned long long int), ptr);
	else if (ft_strcmp(ptr->modifier, "h") == 0)
		print_o((unsigned short)va_arg(ap, int), ptr);
	else if (ft_strcmp(ptr->modifier, "hh") == 0)
		print_o((unsigned char)va_arg(ap, int), ptr);
	else if (ft_strcmp(ptr->modifier, "j") == 0)
		print_o(va_arg(ap, uintmax_t), ptr);
	else if (ft_strcmp(ptr->modifier, "z") == 0)
		print_o(va_arg(ap, size_t), ptr);
}
