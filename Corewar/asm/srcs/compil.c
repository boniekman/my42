/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compil.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:09:20 by mbonowic          #+#    #+#             */
/*   Updated: 2016/07/18 18:10:50 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void				op_to_bin__(t_op *op, int *fd)
{
	int				i;
	int				j;

	if (op->type == LABEL)
		return ;
	ft_putchar_fd(op->opcode, *fd);
	if (op->ocp)
		ft_putchar_fd(op->ocp, *fd);
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < op->param[i].size)
			ft_putchar_fd(op->param[i].arr[j], *fd);
	}
}

static int			get_cor_fd(char *filename)
{
	char			*cor_file;
	int				fd;

	ft_strclr(ft_strrchr(filename, '.'));
	cor_file = ft_strjoin(filename, ".cor");
	fd = open(cor_file, O_CREAT | O_WRONLY, 0755);
	ft_strdel(&cor_file);
	return (fd);
}

static void			compute_size(t_op *op, unsigned int *count)
{
	if (op->type != LABEL)
		*count += op->size;
}

int					compile(t_bin *bin, char *filename)
{
	int				fd;
	unsigned int	size;

	size = 0;
	ft_lst_iter(bin->op, (void(*)(void*, void*))compute_size, &size);
	if ((fd = get_cor_fd(filename)) == -1)
		ft_putendl_fd("asm: cannot create .cor file", STDERR_FILENO);
	else
	{
		bin->header->prog_size = reverse_byte(size);
		write(fd, bin->header, sizeof(t_header));
		ft_lst_iter(bin->op, (void(*)(void*, void*))op_to_bin__, (void*)&fd);
		close(fd);
	}
	return (1);
}
