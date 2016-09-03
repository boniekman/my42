/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:55:59 by ngrasset          #+#    #+#             */
/*   Updated: 2015/12/18 14:35:06 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <libft.h>
# define BUF_SIZE 20

typedef struct		s_piece
{
	char			letter;
	char			**data;
	int				off_x;
	int				off_y;
	int				width;
	int				height;
	struct s_piece	*next;
}					t_piece;

typedef struct		s_matrix
{
	int				size;
	char			**data;
}					t_matrix;

typedef struct		s_controller
{
	t_piece			*input;
	t_matrix		*matrix;
	char			val_max;
}					t_controller;

t_controller		*create_controller(void);
void				delete_controller(t_controller *controller);
t_piece				*new_piece(char **data, int index);
void				push_piece_back(t_piece **head, t_piece *new);
void				delete_list(t_piece *head);
int					find_piece_width(char **data);
int					find_piece_height(char **data);
void				find_piece_offset(char **data, int *off_x, int *off_y);
int					find_min_res_size(t_piece *head);
char				find_piece_max_index(t_piece *head);
void				open_file(char const *file_name, t_controller *controller);
void				parse_file(int fd, t_controller *controller);
int					check_square(char **square);
void				check_block_contact(char **square, int i, int j,
						int *contact);
void				fatal(void);
void				fatal_free_controller(t_controller *controller);
t_matrix			*create_matrix(t_controller *controller);
void				grow_matrix(t_matrix *matrix);
void				delete_matrix(t_matrix *matrix);
void				remove_letter(char **tab, char letter);
char				**create_square_strtab(int len);
void				delete_strtab(char **tab);
int					is_line_empty(char **tab, int i);
int					is_column_empty(char **tab, int j);
int					place_pieces_recur(t_controller *ctr, t_piece *current);
void				put_piece(char **tab, t_piece *piece, int line, int column);
int					is_piece_placeable(t_matrix *matrix, t_piece *piece,
						int l, int c);

#endif
