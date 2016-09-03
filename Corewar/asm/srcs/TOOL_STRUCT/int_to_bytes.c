/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_bytes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:07:55 by mbonowic          #+#    #+#             */
/*   Updated: 2016/07/18 18:07:57 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		is_special_inst(int opcode)
{
	if (opcode == 9 || opcode == 10 || opcode == 11 || opcode == 12 ||
		opcode == 15 || opcode == 14)
		return (1);
	return (0);
}

int		is_special_direct(int opcode)
{
	if (opcode == 6 || opcode == 7 || opcode == 8)
		return (1);
	return (0);
}

t_param	*four_bytes_param(char *param, t_param *par)
{
	int nbr;

	if (param[0] == '%')
		nbr = ft_atoi(param + 1);
	else
		nbr = ft_atoi(param);
	par->size = 4;
	par->arr[3] = nbr & 0xFF;
	par->arr[2] = (nbr >> 8) & 0xFF;
	par->arr[1] = (nbr >> 16) & 0xFF;
	par->arr[0] = (nbr >> 24) & 0xFF;
	return (par);
}

t_param	*two_bytes_param(char *param, t_param *par, int mode, int special)
{
	int nbr;

	if (param[0] == '%')
		nbr = ft_atoi(param + 1);
	else if (param[0] == '%' && param[1] == ':')
		nbr = ft_atoi(param + 2);
	else
		nbr = ft_atoi(param);
	if (mode == 1)
		par->size = 2;
	if (special)
	{
		par->arr[3] = nbr & 0xFF;
		par->arr[2] = (nbr >> 8) & 0xFF;
		par->arr[1] = 0;
		par->arr[0] = 0;
	}
	else
	{
		par->arr[1] = nbr & 0xFF;
		par->arr[0] = (nbr >> 8) & 0xFF;
		par->arr[2] = 0;
		par->arr[3] = 0;
	}
	return (par);
}
