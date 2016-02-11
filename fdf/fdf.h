/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 13:39:48 by mbonowic          #+#    #+#             */
/*   Updated: 2016/02/10 20:56:23 by mbonowic         ###   ########.fr       */
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
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	unsigned	color;
}				t_point;

typedef struct	s_map
{
	t_point		**tab;
	int			columns;
	int			rows;
	int			max_z;
	int			scale;
}				t_map;

typedef struct	s_mlx_att
{
	void		*mlx;
	void		*win;
	t_map		*map;
	char		af;
}				t_mlx_att;

int				get_next_line(int fd, char **line);
int				set_map(t_map *map, char *filename);
char			**ft_split(char *str);

int				start_mlx(t_map *map, int offx, int offy);
void			put_lines(t_mlx_att all);
void			end(t_map *map);

unsigned		count_color(int max_z, int z);
unsigned		color(t_point a, t_point b);

void			cavalery(t_mlx_att all, int offx, int offy);
void			par(t_mlx_att all, int offx, int offy);

#endif
