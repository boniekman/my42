/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:00:14 by mbonowic          #+#    #+#             */
/*   Updated: 2016/07/18 18:00:15 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int	check_addr(char *str, t_lst *lst)
{
	t_lst_elem__	*token;
	char			*tmp;

	tmp = ft_strjoin(str, ":");
	token = lst->head;
	while (token)
	{
		if (!((t_token *)(token->data))->label)
		{
			token = token->next;
			continue ;
		}
		if (!ft_strcmp(((t_token *)(token->data))->label, tmp))
		{
			ft_strdel(&tmp);
			return (-1);
		}
		token = token->next;
	}
	ft_strdel(&tmp);
	return (1);
}

int			check_direct_2(char *str, t_lst *lst)
{
	int err;
	int tmp;

	err = 0;
	if (str[0] == '\0' || str[0] != '%' || str[1] != ':')
	{
		err++;
		return (err);
	}
	tmp = check_addr(str + 2, lst);
	if (tmp > 0)
		err += tmp;
	return (err);
}

int			check_register(char *str)
{
	int err;
	int i;

	err = 0;
	i = 1;
	if (str[0] != 'r')
		return (1);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			err++;
		i++;
	}
	i = (i == 1) ? -1 : ft_atoi(str + 1);
	if (i < 0 || i > REG_NUMBER)
		err++;
	return (err);
}

int			check_direct_4(char *str)
{
	int	i;
	int	err;

	i = 1;
	err = 0;
	if (str[0] != '%' || str[0] == '\0')
		err++;
	while (str[i] != '\0')
	{
		if (str[i] == '-' && i != 1)
			err++;
		if (!ft_isdigit(str[i]) && str[i] != '-')
			err++;
		i++;
	}
	return (err);
}

int			check_indirect(char *str, t_lst *lst)
{
	int i;
	int err;

	i = 0;
	err = 0;
	if (str[0] == ':')
		return (check_addr(str + 1, lst));
	while (str[i] != '\0')
	{
		if (str[i] == '-' && i != 0)
			err++;
		if (!ft_isdigit(str[i]) && str[i] != '-')
			err++;
		i++;
	}
	return (err);
}
