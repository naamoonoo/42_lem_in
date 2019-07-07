/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:31:49 by hnam              #+#    #+#             */
/*   Updated: 2019/07/07 00:49:14 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../lib/includes/ft_printf.h"
# include "../lib/includes/libft.h"

# define CAPACITY 100

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
	int				is_valid;
	int				n_ant;
	int				length;
	struct s_room	*prev;
	struct s_queue	*neighbors;
}					t_room;

typedef struct		s_node
{
	int				key;
	t_room			*room;
	struct s_node	*next;
	// struct s_node	*prev;
	// int				length;
}					t_node;

typedef struct		s_hash
{
	t_node			**n;
	t_room			*start;
	t_room			*end;
	int				capacity;
	int				ant_num;
	int				size;
}					t_hash;

typedef struct		s_queue
{
	t_node			*front;
	t_node			*end;
	int				size;
}					t_queue;

typedef struct		s_stack
{
	t_node			*top;
}					t_stack;

int					initialize_data(t_hash *hash);
t_room				*init_room(char *line, int is_start, int is_end);
void				add_room(t_hash *hash, char *line, int is_start, int is_end);
void				add_neighbor(t_hash *hash, char *line);
void				enqueue_neighbor(t_room *room, t_room *neighbor);

t_queue				*init_queue();
void				enqueue(t_queue *queue, t_room *room);
void				enqueue_by_order(t_queue *queue, t_room *room, int key);
t_room				*dequeue(t_queue *queue);
void				free_queue(t_queue *queue);

t_stack 			*init_stack(void);
t_room				*pop(t_stack *stack);
void				push(t_stack *stack, t_room *room);
void				free_stack(t_stack *stack);

t_hash				*init_hash(int capacity);
int					get_hash(char *key, int capacity);
void				hash_insert(t_hash *hash, t_room *room);
t_room				*hash_find(t_hash *hash, char *key);
void				free_hash(t_hash *hash, int is_last);


int					bfs_algo(t_hash *hash);
void				dup_handle_q(t_hash *unique, t_queue *neighbor, t_queue *que);


t_queue				**get_paths(t_hash *hash);
t_queue				*find_path(t_hash *hash, t_room *start);
t_queue				*path_make(t_hash *hash);
void				daijkstra(t_hash *unique, t_queue *neighbor, t_queue *que, t_room *parent);

void				hash_default_set(t_hash *hash);
int					is_error(t_hash *hash);


void				print_hash(t_hash	*hash);




#endif
