/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 17:59:04 by mbonowic          #+#    #+#             */
/*   Updated: 2016/07/18 17:59:46 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static t_token	*str_to_token(char *line)
{
	int			i;
	char		**tab;
	t_token		*new;

	i = 0;
	tab = ft_strsplit_mul(line, " ,\t");
	if (ft_arr_len((void*)tab) == 0 || ft_arr_len((void*)tab) > 4)
		exit(ft_putendl_fd("asm: invalid line", STDERR_FILENO));
	new = token_new();
	new->type = INSTR;
	while (tab[i])
	{
		if (i == 0)
			new->opcode = tab[i];
		if (i == 1)
			new->param1 = tab[i];
		if (i == 2)
			new->param2 = tab[i];
		if (i == 3)
			new->param3 = tab[i];
		i++;
	}
	free(tab);
	return (new);
}

static char		*format_line__(char *line)
{
	ft_replace_char(line, '\t', ' ');
	if (ft_strchr(line, COMMENT_CHAR))
		ft_strclr(ft_strchr(line, COMMENT_CHAR));
	if (ft_strchr(line, ';'))
		ft_strclr(ft_strchr(line, ';'));
	line = ft_strtrim_free(line);
	if (!ft_strlen(line))
		ft_strdel(&line);
	return (line);
}

t_lst			*parse_file(int fd)
{
	t_lst		*lst;
	t_token		*new_token;
	char		*line;

	line = NULL;
	lst = ft_lst_new();
	while (get_next_line(fd, &line) > 0)
	{
		if (!(line = format_line__(line)))
			continue ;
		if ((new_token = is_label(line)) != NULL)
			ft_lst_push_back(lst, (void*)new_token);
		if (ft_strlen(line))
			ft_lst_push_back(lst, (void*)str_to_token(line));
		ft_strdel(&line);
	}
	return (lst);
}
