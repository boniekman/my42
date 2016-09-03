/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 15:33:58 by akpenou           #+#    #+#             */
/*   Updated: 2016/07/19 18:30:34 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static char		*ft_itoa_b(double n, char *base)
{
	char				*nbr;
	int					len;
	long int			pow;
	long int			unsigned_n;
	int					size_base;

	pow = 1;
	len = 1;
	unsigned_n = (n < 0) ? (long int)-n : (long int)n;
	size_base = ft_strlen(base);
	while (n / pow > size_base && ++len)
		pow *= size_base;
	if (!(nbr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	nbr[len] = '\0';
	len = 0;
	while (pow > 0)
	{
		nbr[len] = base[(int)(unsigned_n / pow) % size_base];
		pow /= size_base;
		len++;
	}
	return (nbr);
}

static void		dump_size(int size)
{
	size_t	i;
	char	*str;

	i = 4;
	str = ft_itoa_b(size, "0123456789abcdef");
	ft_putstr("0x");
	while (i > ft_strlen(str))
	{
		ft_putchar('0');
		i--;
	}
	ft_putstr(str);
	ft_putstr(" : ");
	ft_strdel(&str);
}

static void		dump_octet(unsigned char octet)
{
	char *str;

	str = ft_itoa_b(octet, "0123456789abcdef");
	if (ft_strlen(str) == 1)
		ft_putchar('0');
	ft_putstr(str);
	ft_strdel(&str);
}

int				dump_mem(void)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
		{
			dump_size(size);
			size += 64;
		}
		dump_octet(g_vm.ram[i]);
		i++;
		ft_putchar((i % 64 == 0) ? '\n' : ' ');
	}
	return (1);
}
