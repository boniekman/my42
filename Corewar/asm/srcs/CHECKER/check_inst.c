/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:00:41 by mbonowic          #+#    #+#             */
/*   Updated: 2016/07/18 18:00:43 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		check_zjmp(t_token *token, t_lst *lst)
{
	int error;

	error = 0;
	if (!(token->param1) && ++error)
		ft_putstr_fd("<zjmp> instruction need one parameter\n", 2);
	else if ((token->param2 || token->param3) && ++error)
		ft_putstr_fd("<zjmp> instruction takes only one parameter\n", 2);
	else if (check_direct_4(token->param1) &&
		check_direct_2(token->param1, lst) && ++error)
		ft_putstr_fd("Invalid 1st parameter for <zjmp> instruction\n", 2);
	return (error);
}

int		check_ldi(t_token *token, t_lst *lst)
{
	int error;

	error = 0;
	if (!(token->param1 && token->param2 && token->param3) && ++error)
		ft_putstr_fd("<ldi> instruction need 3 parameters\n", 2);
	else if (check_direct_2(token->param1, lst) &&
		check_direct_4(token->param1) &&
		check_register(token->param1) && ++error)
		ft_putstr_fd("Invalid 1st parameter for <ldi> instruction\n", 2);
	else if (check_direct_2(token->param2, lst) &&
		check_direct_4(token->param2) &&
		check_register(token->param2) && ++error)
		ft_putstr_fd("Invalid 2nd parameter for <ldi> instruction\n", 2);
	else if (check_register(token->param3) && ++error)
		ft_putstr_fd("Invalid 3thd parameter for <ldi> instruction\n", 2);
	return (error);
}

int		check_sti(t_token *token, t_lst *lst)
{
	int error;

	error = 0;
	if (!(token->param1 && token->param2 && token->param3) && ++error)
		ft_putstr_fd("<sti> instruction need three parameters\n", 2);
	else if (check_direct_2(token->param2, lst) &&
		check_direct_4(token->param2) && check_register(token->param2) &&
		check_indirect(token->param2, lst) > 0 && ++error)
		ft_putstr_fd("Invalid 2nd parameter for <sti> instruction\n", 2);
	else if (check_direct_2(token->param3, lst) &&
			check_direct_4(token->param3) && check_register(token->param3) &&
			check_indirect(token->param3, lst) > 0 && ++error)
		ft_putstr_fd("Invalid 3thd parameter for <sti> instruction\n", 2);
	else if (check_register(token->param1) && ++error)
		ft_putstr_fd("Invalid 1st parameter for <sti> instruction\n", 2);
	return (error);
}

int		check_fork(t_token *token, t_lst *lst)
{
	int error;

	error = 0;
	if (!(token->param1) && ++error)
		ft_putstr_fd("<fork> instruction need one parameter\n", 2);
	else if ((token->param2 || token->param3) && ++error)
		ft_putstr_fd("<fork> instruction takes only one parameter\n", 2);
	else if (check_direct_2(token->param1, lst) &&
			check_direct_4(token->param1) && ++error)
		ft_putstr_fd("Invalid 1st parameter for <fork> instruction\n", 2);
	return (error);
}

int		check_aff(t_token *token)
{
	int error;

	error = 0;
	if (!(token->param1) && ++error)
		ft_putstr_fd("<aff> instruction need one parameter\n", 2);
	else if ((token->param2 || token->param3) && ++error)
		ft_putstr_fd("<aff> instruction takes only one parameter\n", 2);
	else if (check_register(token->param1) && ++error)
		ft_putstr_fd("Invalid 1st parameter for <aff> instruction\n", 2);
	return (error);
}
