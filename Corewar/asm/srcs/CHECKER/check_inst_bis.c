/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inst_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:00:55 by mbonowic          #+#    #+#             */
/*   Updated: 2016/07/18 18:00:56 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		check_live(t_token *token, t_lst *lst)
{
	int error;

	error = 0;
	if (!(token->param1) && ++error)
		ft_putstr_fd("<Live> instruction need a parameter\n", 2);
	else if ((token->param2 || token->param3) && ++error)
		ft_putstr_fd("<Live> instruction takes only one parameter\n", 2);
	else if (check_direct_4(token->param1) &&
			check_direct_2(token->param1, lst) && ++error)
		ft_putstr_fd("Invalid parameter for <Live> instruction\n", 2);
	return (error);
}

int		check_ld(t_token *token, t_lst *lst)
{
	int error;

	error = 0;
	if (!(token->param1 && token->param2) && ++error)
		ft_putstr_fd("<ld> instruction need two parameters\n", 2);
	else if (token->param3 && ++error)
		ft_putstr_fd("<ld> instruction takes only two parameters\n", 2);
	else if (check_parameter(token->param1, lst, 0) && ++error)
		ft_putstr_fd("Invalid first parameter for <ld> instruction\n", 2);
	else if ((check_register(token->param2) && ++error))
		ft_putstr_fd("Invalid second parameter for <ld> instruction\n", 2);
	return (error);
}

int		check_st(t_token *token, t_lst *lst)
{
	int error;

	error = 0;
	if (!(token->param1 && token->param2) && ++error)
		ft_putstr_fd("<st> instruction need two parameters\n", 2);
	else if (token->param3 && ++error)
		ft_putstr_fd("<st> instruction takes only two parameters\n", 2);
	else if (check_register(token->param1) && ++error)
		ft_putstr_fd("Invalid 1st parameter for <st> instruction\n", 2);
	else if ((check_register(token->param2) &&
				check_indirect(token->param2, lst) > 0) && ++error)
		ft_putstr_fd("Invalid 2nd parameter for <st> instruction\n", 2);
	return (error);
}

int		check_add_sub(t_token *token)
{
	int error;

	error = 0;
	if (!(token->param1 && token->param2 && token->param3) && ++error)
		ft_putstr_fd("<add/sub> instructions need three parameters\n", 2);
	else if (check_register(token->param1) && ++error)
		ft_putstr_fd("Invalid 1st parameter for <add/sub> instructions\n", 2);
	else if (check_register(token->param2) && ++error)
		ft_putstr_fd("Invalid 2nd parameter for <add/sub> instructions\n", 2);
	else if (check_register(token->param3) && ++error)
		ft_putstr_fd("Invalid 3thd parameter for <add/sub> instructions\n", 2);
	return (error);
}

int		check_logical(t_token *token, t_lst *lst)
{
	int error;

	error = 0;
	if (!(token->param1 && token->param2 && token->param3) && ++error)
		ft_putstr_fd("<logicals> instructions need three parameters\n", 2);
	else if (check_parameter(token->param1, lst, 0) && ++error)
		ft_putstr_fd("Invalid 1st parameter for <logic> instructions\n", 2);
	else if (check_parameter(token->param2, lst, 0) && ++error)
		ft_putstr_fd("Invalid 2nd parameter for <logic> instructions\n", 2);
	else if (check_register(token->param3) && ++error)
		ft_putstr_fd("Invalid 3thd parameter for <logic> instructions\n", 2);
	return (error);
}
