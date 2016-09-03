/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 13:24:59 by akpenou           #+#    #+#             */
/*   Updated: 2016/07/18 13:25:02 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIZU_H
# define VIZU_H

# include <ncurses.h>
# include <panel.h>
# include <stdlib.h>

# define P1		1
# define P2		2
# define P3		3
# define P4		4
# define PC1	5
# define PC2	6
# define PC3	7
# define PC4	8
# define BLUE	9
# define GREEN	10
# define RED	11
# define YELLOW	12
# define GREY	13
# define WHITE	14

typedef struct		s_vizu
{
	char			*color[4];
	PANEL			*memory;
	PANEL			*wmain;
	int				onoff;
	int				play;
	int				player[5];
	int				speed;
	int				maxcheck;
}					t_vizu;

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

int					ft_initncurses(void);
void				ft_refresh(t_vizu *vizu);
int					ft_key(int c);
void				ft_endncurses(char *s);
void				ft_exitmenu(void);
void				ft_printvm(void);
void				ft_activity(WINDOW *wmain, char activity);
PANEL				*ft_home(int x, int y);
WINDOW				*ft_makewin(t_coord dim, t_coord coord, int putborder);
WINDOW				*ft_memory(WINDOW *memory);
void				vwrite_mem(int color, void *memoire, size_t index,
																	size_t len);
void				ft_player(WINDOW *wmain);
t_coord				ft_makecoord(int x, int y);

#endif
