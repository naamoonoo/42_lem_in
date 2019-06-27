/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:31:49 by hnam              #+#    #+#             */
/*   Updated: 2019/06/27 00:01:40 by hnam             ###   ########.fr       */
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
	int				n_ant;
	struct s_queue	*neighbors;
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
	t_room			*start;
	int				capacity;
}					t_hash;

typedef struct		s_queue
{
	t_node			*front;
	t_node			*end;
	int				size;
}					t_queue;

int					initialize_data(t_hash *hash);
t_room				*init_room(char *line, int is_start, int is_end);
void				add_room(t_hash *hash, char *line, int is_start, int is_end);
void				add_neighbor(t_hash *hash, char *line);

t_queue				*init_queue();
void				enqueue(t_queue *queue, t_room *room);
t_room				*dequeue(t_queue *queue);
void				extend_queue(t_queue *queue, t_queue *add);
void				free_queue(t_queue *queue);

t_hash				*init_hash(int capacity);
int					get_hash(char *key, int capacity);
void				hash_insert(t_hash *hash, t_room *room);
t_room				*hash_find(t_hash *hash, char *key);
void				free_hash(t_hash *hash);

void				print_hash(t_hash	*hash);

void	find_path(t_hash *hash);
void	dup_handle(t_hash *unique, t_queue *neighbor, t_queue *que);



#endif
