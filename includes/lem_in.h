/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:31:49 by hnam              #+#    #+#             */
/*   Updated: 2019/06/24 17:39:55 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../lib/includes/ft_printf.h"
# include "../lib/includes/libft.h"

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

// typedef struct		s_neighbor
// {
// 	struct t_room	*neighbor;
// 	int				cnt;
// }					t_neigh;


typedef struct		s_vector
{
	struct s_room	*front;
	struct s_room	*end;
	int				size;
}					t_vec;

typedef struct		s_room
{
	char			*name;
	t_point			point;
	int				is_start;
	int				is_end;
	int				n_ant;
	struct s_room	**connected;
	// t_vec			*neighbors;
	struct s_room	*next;
}					t_room;

typedef struct		s_lem_in
{
	int				n_ants;
	t_room			*rooms;
	char			*passed;
}					t_li;

int					initialize_data(t_vec *v, int fd);
t_room				*init_room(char *line, int is_start, int is_end);
void				init_connected(t_vec *v, t_room *room, t_room *neighbor);

int					read_data(char *line);
void				add_room(t_vec *v, char *line, int is_start, int is_end);
void				add_neighbor(t_vec *v, char *line);
int		check_existed(t_room *room, char *name);


t_vec				*init_vector();
void				push_back(t_vec *v, t_room *room);
t_room				*pop_back(t_vec *v);
void				insert(t_vec *v, t_room *room);
t_room				*erase(t_vec *v);
t_room				*get(t_vec *v, int idx);
t_room				*get_by_name(t_vec *v, char *name);
int					empty(t_vec *v);
int					size(t_vec *v);

void	print_vec(t_vec	*v);


#endif
