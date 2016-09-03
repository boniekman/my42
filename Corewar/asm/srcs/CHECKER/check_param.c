/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:01:04 by mbonowic          #+#    #+#             */
/*   Updated: 2016/07/18 18:01:08 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		check_parameter(char *str, t_lst *lst, int mode)
{
	if (check_indirect(str, lst) <= 0)
		return (0);
	if (!check_direct_4(str) && mode == 0)
		return (0);
	if (!check_register(str))
		return (0);
	if (!check_direct_2(str, lst))
		return (0);
	return (1);
}
