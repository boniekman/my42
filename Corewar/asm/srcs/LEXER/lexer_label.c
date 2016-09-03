/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:03:02 by mbonowic          #+#    #+#             */
/*   Updated: 2016/07/18 18:03:04 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static bool		is_valid_label(char *label)
{
	while (*label)
	{
		if (!ft_strchr(LABEL_CHARS, *label))
			return (FALSE);
		label++;
	}
	return (TRUE);
}

static int		del_first_word(char *line, char **tab)
{
	int i;

	i = 1;
	ft_memset(line, 0, ft_strlen(line));
	while (tab[i])
	{
		line = ft_strcat(line, tab[i]);
		if (tab[i + 1])
			ft_add_char(line, ':');
		i++;
	}
	return (1);
}

t_token			*is_label(char *line)
{
	t_token	*new;
	char	**tab;

	if (!ft_strchr(line, ':'))
		return (NULL);
	new = NULL;
	tab = ft_strsplit(line, ':');
	if (is_valid_label(tab[0]) == TRUE)
	{
		new = token_new();
		new->type = LABEL;
		new->label = ft_strjoin(tab[0], ":");
		del_first_word(line, tab);
	}
	ft_arr_del(tab, free);
	return (new);
}
