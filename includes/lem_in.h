/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:31:49 by hnam              #+#    #+#             */
/*   Updated: 2019/06/26 18:40:20 by hnam             ###   ########.fr       */
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

typedef struct		s_room
{
	char			*name;
	t_point			point;
	int				is_start;
	int				is_end;
	int				n_ant;
	struct s_hash	*neighbors;
}					t_room;

typedef struct		s_node
{
	int				key;
	t_room			*room;
	struct s_node	*next;
}					t_node;

typedef struct		s_hash
{
	t_node			**n;
	int				capacity;
}					t_hash;

typedef struct		s_queue
{
	t_node			*front;
	t_node			*end;
	int				size;
}					t_queue;

typedef struct		s_lem_in
{
	int				n_ants;
	t_room			*rooms;
	char			*passed;
}					t_li;

int					initialize_data(t_hash *hash, int fd);
t_room				*init_room(char *line, int is_start, int is_end);
void				init_connected(t_hash *hash, t_room *room, t_room *neighbor);

int					read_data(char *line);
void				add_room(t_hash *hash, char *line, int is_start, int is_end);
void				add_neighbor(t_hash *hash, char *line);
int		check_existed(t_room *room, char *name);


// t_hash		hash();
// void				push_back(t_hash *hash, t_room *room);
// t_room				*pop_back(t_hash *hash);
// void				insert(t_hash *hash, t_room *room);
// t_room				*erase(t_hash *hash);
// t_room				*get(t_hash *hash, int idx);
// t_room				*get_by_name(t_hash *hash, char *name);
// int					empty(t_hash *hash);
// int					size(t_hash *hash);

t_queue	*init_queue();
void	push_end(t_queue *queue, t_room *room);
t_room	*pop_front(t_queue *queue);


void	print_hash(t_hash	*hash);


#endif
