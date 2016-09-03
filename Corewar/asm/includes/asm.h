/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 17:57:49 by mbonowic          #+#    #+#             */
/*   Updated: 2016/07/18 17:57:56 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <libft.h>

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER			4
# define MEM_SIZE				(4 * 1024)
# define IDX_MOD					(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define REG_NUMBER				16

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define LABEL 1
# define INSTR 2

# define PROG_NAME_LENGTH		128
# define COMMENT_LENGTH			2048
# define COREWAR_EXEC_MAGIC		0xea83f3
# define COREWAR_MAGIC			0xf383ea00

# define TRUE 1
# define FALSE 0

typedef struct		s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_token
{
	char			type;
	char			*label;
	char			*opcode;
	char			*param1;
	char			*param2;
	char			*param3;
}					t_token;

typedef struct		s_param
{
	unsigned char	arr[4];
	char			size;
}					t_param;

typedef struct		s_op
{
	int				type;
	int				size;
	int				addr;
	char			ocp;
	char			opcode;
	t_param			param[3];
	char			*label;
}					t_op;

typedef struct		s_bin
{
	t_header		*header;
	t_lst			*op;
}					t_bin;

/*
** lexer
*/
t_header			*get_header(int fd);
t_lst				*parse_file(int fd);

/*
** check_lexer
*/
int					check_errors(t_lst *token);
int					check_register(char *str);
int					check_direct_4(char *str);
int					check_indirect(char *str, t_lst *lst);
int					check_direct_2(char *str, t_lst *lst);
int					check_parameter(char *str, t_lst *lst, int mode);
int					check_live(t_token *token, t_lst *lst);
int					check_ld(t_token *token, t_lst *lst);
int					check_st(t_token *token, t_lst *lst);
int					check_add_sub(t_token *token);
int					check_logical(t_token *token, t_lst *lst);
int					check_zjmp(t_token *token, t_lst *lst);
int					check_ldi(t_token *token, t_lst *lst);
int					check_sti(t_token *token, t_lst *lst);
int					check_fork(t_token *token, t_lst *lst);
int					check_aff(t_token *token);

/*
** lexer_tools
*/
int					open_file(char *filename);
t_token				*is_label(char *line);
unsigned int		reverse_byte(unsigned int number);

/*
** token structure
*/
t_token				*token_new(void);
void				token_del(t_token *token);
int					print_token(t_token *token);

/*
** structure op
*/
t_op				*op_new(void);
void				op_del(t_op *op);
int					print_op(t_op *op);

/*
** parser
*/
t_lst				*token_to_op(t_lst *token);
void				parser_params(t_lst *op, t_lst *token);
void				parser_label(t_lst *op, t_lst *token);
t_param				*four_bytes_param(char *param, t_param *par);
t_param				*two_bytes_param(char *param, t_param *par, int mode,
	int special);
int					is_special_inst(int opcode);
int					is_special_direct(int opcode);
void				parser_addr(t_lst *op, t_lst *token);
int					param_type(char *param, t_lst *lst);

/*
** compilation
*/
int					compile(t_bin *bin, char *filename);

#endif
