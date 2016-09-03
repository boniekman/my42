/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 13:24:51 by akpenou           #+#    #+#             */
/*   Updated: 2016/07/18 17:22:24 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include <libft.h>
# include "vizu.h"

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4 * 1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

typedef char	t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3
# define COREWAR_TRUE_MAGIC		0x00f383ea00
# define HEADER_SIZE			2192

# define M_D4 2
# define M_D2 2
# define M_REG 1
# define M_IND 3

# define MODE_REG 0b001
# define MODE_DIR 0b010
# define MODE_IND 0b100

# define PARAM    params.param
# define MODE    params.mode

# define UNUSED(x) (void)(x)

typedef struct		s_vm {
	char			ram[MEM_SIZE];
	t_vizu			*vizu;
	t_lst			*champs;
	t_lst			*procs;
	int				dump;

	int				actual_cycle;
	int				cycle_to_die;
	int				cycle_to_check;
	int				total_live;
	int				id;
	unsigned		last_live;
}					t_vm;

typedef struct		s_params {
	int				step;
	unsigned char	ocp;
	unsigned char	opcode;
	char			mode[3];
	int				param[3];
}					t_params;

typedef struct		s_champ {
	char			*name;
	unsigned		id;
	char			*body;
	int				no;
	unsigned int	size;
	unsigned int	live;
	unsigned int	proc;
	bool			alive;
}					t_champ;

typedef struct		s_proc {
	int				no;
	int				pc;
	int				start;
	char			reg[REG_NUMBER][REG_SIZE];
	int				cycles;
	t_params		params;
	char			carry;
	bool			alive;
	int				id;
}					t_proc;

typedef	void(*t_fnptr)(t_proc*);

typedef struct		s_op
{
	t_fnptr			fn;
	int				nbr_cycle;
}					t_op;

extern t_vm	g_vm;

/*
** VM managment
*/

int					init_vm(void);
void				free_vm(void);
void				fatal_exit_vm(char *message);
int					end_program(void);

/*
** Parsing champions
*/

int					parse_all_champs(int ac, char **av);
int					parse_champ(char *filename, int id);
int					open_champ_file(char *filename);
int					get_header_body(int fd, t_champ *champ);
int					check_magic(char *buffer);
void				set_remaining_id(void);
int					is_free_id(int id);
int					put_in_ram(void);

/*
** Execution
*/
int					ft_cycle_to_die(void);
void				op_controller(t_proc *proc);
void				ft_execution(void);

/*
** Operations
*/
void				op_zjmp(t_proc *proc);
void				op_ldi(t_proc *proc);
void				op_add(t_proc *proc);
void				op_sub(t_proc *proc);
void				op_and(t_proc *proc);
void				op_or(t_proc *proc);
void				op_xor(t_proc *proc);
void				op_aff(t_proc *proc);
void				op_fork(t_proc *proc);
void				op_lfork(t_proc *proc);
void				op_st(t_proc *proc);
void				op_sti(t_proc *proc);
void				op_live(t_proc *proc);
void				op_ld(t_proc *proc);
void				op_lld(t_proc *proc);
void				op_lldi(t_proc *proc);

/*
** Tools
*/
int					get_reg(unsigned char registre[REG_SIZE]);
int					get_indirect(t_proc *prc, int pos);
int					get_lindirect(t_proc *prc, int pos);
unsigned int		get_param(t_proc *prc, int n, int *res);
unsigned int		get_lparam(t_proc *prc, int n, int *res);
void				store_registre(char registre[REG_SIZE], unsigned int n);
int					get_direct(t_proc *prc, int pos);
int					check_params(t_proc *proc);
unsigned int		reverse_int(unsigned int number);
unsigned short		reverse_short(unsigned short number);
int					dump_mem(void);
void				write_in_ram(int start, int index, int n, int no);
t_champ				*get_champ_by_no(unsigned int no);
t_champ				*get_champ_by_id(unsigned int id);
void				print_proc(t_proc *prc, bool aff);
void				print_op(t_proc *prc, char *op, int p1, int p2, int p3);
int					is_direct_2(char opcode);

/*
** Debug
*/

#endif
