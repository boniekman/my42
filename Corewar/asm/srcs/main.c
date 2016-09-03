/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:08:41 by mbonowic          #+#    #+#             */
/*   Updated: 2016/07/18 18:09:03 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static int	exit_asm(t_bin *bin, int fd, t_lst *token)
{
	free(bin->header);
	ft_lst_del(token, (void(*)(void*))token_del);
	ft_lst_del(bin->op, (void(*)(void*))op_del);
	free(bin);
	return (close(fd));
}

static int	parse_and_compile(t_bin *bin, t_lst *token, char *filename)
{
	parser_params(bin->op, token);
	parser_label(bin->op, token);
	parser_addr(bin->op, token);
	compile(bin, filename);
	return (1);
}

int			main(int ac, char **av)
{
	int		fd;
	t_bin	*bin;
	t_lst	*token;

	if (ac != 2)
		return (1);
	if ((fd = open_file(av[1])) < 0)
		return (ft_putendl_fd("asm: wrong file type", STDERR_FILENO));
	bin = ft_memalloc(sizeof(t_bin));
	bin->header = get_header(fd);
	token = parse_file(fd);
	if (check_errors(token) > 0)
		return (close(fd));
	bin->op = token_to_op(token);
	parse_and_compile(bin, token, av[1]);
	return (exit_asm(bin, fd, token));
}
