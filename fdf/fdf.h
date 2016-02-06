/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 13:39:48 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/07 00:13:11 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 32
# define RAD 0.0175
# define TERM_W 1500
# define TERM_H 1000

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

typedef struct	s_point
{
	double		x;
	double		y;
	int			z;
}				t_point;

typedef struct	s_map
{
	t_point		**tab;
	int			columns;
	int			rows;
	int			max_z;
}				t_map;

typedef struct	s_mlx_att
{
	void		*mlx;
	void		*win;
	t_map		*map;
}				t_mlx_att;

int				get_next_line(int fd, char **line);
int				set_map(t_map *map, char *filename);
int				set_row(char *str, t_map *map, int posx);
int				er_msg(void);
char			**ft_split(char *str);

int				start_mlx(t_map *map, int offx, int offy);
void			put_lines(t_mlx_att all);

void			cavalery(t_mlx_att, int offx, int offy);

#endif
