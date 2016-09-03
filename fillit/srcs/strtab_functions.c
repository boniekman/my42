/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtab_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:27:07 by ngrasset          #+#    #+#             */
/*   Updated: 2015/12/02 16:05:52 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void	remove_letter(char **tab, char letter)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == letter)
				tab[i][j] = '.';
			j++;
		}
		i++;
	}
}

char	**create_square_strtab(int len)
{
	char	**tab;
	int		i;

	tab = (char **)malloc(sizeof(char *) * len + 1);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < len)
	{
		tab[i] = ft_strnew(len + 1);
		if (!tab[i])
			return (NULL);
		ft_memset(tab[i], '.', len);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	delete_strtab(char **tab)
{
	char	**start;

	if (!tab)
		return ;
	start = tab;
	while (*tab)
	{
		free(*tab);
		tab++;
	}
	free(start);
}

int		is_line_empty(char **tab, int i)
{
	int		j;

	j = 0;
	if (!tab)
		return (1);
	while (tab[i][j])
	{
		if (tab[i][j] != '.')
			return (0);
		j++;
	}
	return (1);
}

int		is_column_empty(char **tab, int j)
{
	int		i;

	i = 0;
	if (!tab)
		return (1);
	while (tab[i])
	{
		if (tab[i][j] != '.')
			return (0);
		i++;
	}
	return (1);
}
