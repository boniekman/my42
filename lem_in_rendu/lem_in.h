/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonowic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:56:51 by mbonowic          #+#    #+#             */
/*   Updated: 2016/03/17 14:41:56 by mbonowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"

typedef struct		s_node
{
	char			*name;
	int				index;
	int				x;
	int				y;
	struct s_node	*next;
	struct s_node	*cons;
	int				ant;
}					t_node;

typedef struct		s_cons
{
	int				con;
	int				weight;
	int				used;
}					t_cons;

typedef struct		s_route
{
	int				node;
	int				ant;
	struct s_route	*prev;
	struct s_route	*next;
}					t_route;

typedef struct		s_all
{
	long long		ants;
	int				size;
	struct s_cons	**cons;
	struct s_node	*room;
	struct s_node	*arr_of_rooms;
	struct s_route	**routes;
	int				start;
	int				end;
}					t_all;

/* ************ LIST FUNCTIONS ****************** */

t_node				*create_new(char *name, int x, int y);
int					add_elem(t_node **list, t_node *node);
int					del_elem(t_node **list);
int					del_list(t_node **list);

/* ************ ROAD FUNCTIONS ****************** */

void				add_route(t_route **route, int index);
void				del_route(t_route **route);
/* ************ PARSING FUNCTIONS ****************** */

int					init(t_all *all, char **error);
int					read_restrictions(char **error, char **line, int c);
int					take_rooms(t_all *all, char **error);
int					is_room(char *s, char **error);
int					is_number(char *s);
void				take_comm(t_all *all, char *line, char **error, int index);
void				add_room(t_all *all, char *line, char **error);
int					arr_of_rooms(t_all *all, char **error);
int					is_valid_pass(t_all *all, char *line, char **error);
int					make_cons(t_all *all, char **error, char *line);
void				zero_it(t_all *all);

/* ************ ALGO FUNCTIONS ****************** */

int					algo(t_all *all, char **error);
int					search_routes(t_all *all, char **error);

/* ************ DEBUG FUNCTIONS ****************** */

int					print_list(t_node *list);
int					print_arr(t_all all);
int					print_cons(t_all all);
int					print_weights(t_all all);
void				print_routes(t_all all);

#endif
