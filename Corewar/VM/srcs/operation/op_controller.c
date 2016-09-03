/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_controller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 13:28:33 by akpenou           #+#    #+#             */
/*   Updated: 2016/07/18 17:24:39 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

t_op	g_fn_op[17] = {
	{op_live, 10},
	{op_ld, 5},
	{op_st, 5},
	{op_add, 10},
	{op_sub, 10},
	{op_and, 6},
	{op_or, 6},
	{op_xor, 6},
	{op_zjmp, 20},
	{op_ldi, 25},
	{op_sti, 25},
	{op_fork, 800},
	{op_lld, 10},
	{op_lldi, 50},
	{op_lfork, 1000},
	{op_aff, 2},
	{NULL, 0},
};

static int	get_param__(char *memory, int *index, int size)
{
	unsigned int param;

	param = 0;
	ft_memcpy(&param, memory + *index, size);
	*index += size;
	if (size == 2)
	{
		param = reverse_int(param) >> 16;
		return (((1 << 15) & param) ? param | 0xffff0000 : param);
	}
	else if (size == 4)
		return (reverse_int(param));
	return (param);
}

static int	get_param_(t_params *p, char *memory, int *index)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (p->mode[i] == REG_CODE)
			p->param[i] = get_param__(memory, index, 1);
		else if (p->mode[i] == DIR_CODE && !is_direct_2(p->opcode))
			p->param[i] = get_param__(memory, index, 4);
		else if (p->mode[i])
			p->param[i] = get_param__(memory, index, 2);
		i++;
	}
	return (1);
}

static int	get_mode__(t_params *p)
{
	if (p->opcode != 1 && p->opcode != 9 && p->opcode != 12 && p->opcode != 15)
	{
		p->mode[0] = ((p->ocp >> 6));
		p->mode[1] = ((p->ocp >> 4) & 3);
		p->mode[2] = ((p->ocp >> 2) & 3);
	}
	else
		p->mode[0] = DIR_CODE;
	return (1);
}

static int	get_param_from_ram__(t_params *p, int step)
{
	int start;

	start = step;
	ft_memset(p, 0, sizeof(t_params));
	p->opcode = g_vm.ram[step++];
	if (p->opcode != 1 && p->opcode != 9 && p->opcode != 12 && p->opcode != 15)
		p->ocp = g_vm.ram[step++];
	get_mode__(p);
	get_param_(p, g_vm.ram, &step);
	return (step - start);
}

void		op_controller(t_proc *proc)
{
	print_proc(proc, false);
	if (g_vm.actual_cycle == proc->cycles)
	{
		proc->params.step = get_param_from_ram__(&proc->params,
										(proc->start + proc->pc) % MEM_SIZE);
		if (proc->params.opcode - 1 >= 0 && proc->params.opcode - 1 <= 15)
			g_fn_op[(int)proc->params.opcode - 1].fn(proc);
		if (proc->params.opcode != 9)
			proc->pc += proc->params.step;
		proc->cycles = 0;
	}
	if (!proc->cycles)
	{
		proc->params.step = get_param_from_ram__(&proc->params,
										(proc->start + proc->pc) % MEM_SIZE);
		if (!check_params(proc))
		{
			proc->pc++;
			print_proc(proc, true);
			return ;
		}
		proc->cycles = g_vm.actual_cycle +
							g_fn_op[(int)proc->params.opcode - 1].nbr_cycle;
	}
	print_proc(proc, true);
}
