/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 22:48:56 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/24 22:59:38 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_l		*ft_lstnew(char *s, char conv, char *flag, int tmdc, int prec)
{
	t_l	*node;

	if ((node = (t_l*)malloc(sizeof(t_l))) == NULL)
		return (NULL);
	if ((node->s = ft_strdup(s)) == NULL)
	{
		free(node);
		return (NULL);
	}
	if ((node->conv = ft_strdup(conv)) == NULL)
	{
		free(node->s);
		free(node);
		return (NULL);
	}
	node->flag = flag;
	node->prec = prec;
	node->next = NULL;
	return (node);
}

void	ft_lstadd(t_l **alst, t_l *new)
{
	t_l	*tmp;

	tmp = *alst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void	del_lst(t_l **alst)
{
	t_l	*tmp;

	while ((*alst)->next != NULL)
	{
		tmp = *alst;
		(*alst) = (*alst)->next;
		free(tmp->s);
		free(tmp->conv);
		free(tmp);
	}
	free(*alst);
}
