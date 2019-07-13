/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:36:34 by smbaabu           #+#    #+#             */
/*   Updated: 2019/07/12 02:28:50 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_start_empty(t_room *room)
{
	if (room->is_start && !room->neighbors->front)
	{
		ft_printf("start empty! %d\n", room->neighbors->size);
		print_queue(room->neighbors);
		return (1);
	}
	return (0);
}

void	delete_to_start(t_hash *hash, t_room *neighbor)
{
	t_room	*next;

	while (!neighbor->is_start)
	{
		next = neighbor;
		neighbor = neighbor->prev;
		if (!hash_find(hash, next->name))
		{
			ft_printf("ds: deleting %s->%s\n", neighbor->name, next->name);
			delete_queue(&neighbor->neighbors, next);
			check_start_empty(neighbor);
		}
	}
}

void	delete_except(t_room *room, t_room *prev, t_room *next)
{
	t_node	*node;
	t_room	*neighbor;
	int		n;
	int		i;

	n = room->neighbors->size;
	i = -1;
	if (!contains_queue(prev->neighbors, room))
	{
		ft_printf("re: reattaching %s->%s\n", prev->name, room->name);
		ft_printf("before front %s front size %d\n", prev->neighbors->front->room->name, prev->neighbors->size);
		print_queue(prev->neighbors);
		enqueue(prev->neighbors, room);
		ft_printf("after front %s front size %d\n", prev->neighbors->front->room->name, prev->neighbors->size);
		print_queue(prev->neighbors);
	}
	while (++i < n)
	{
		if ((node = room->neighbors->front))
		{
			while (node)
			{
				neighbor = node->room;
				if (neighbor != prev && neighbor != next)
				{
					ft_printf("de: deleting %s->%s\n", room->name, neighbor->name);
					delete_queue(&room->neighbors, neighbor);
					check_start_empty(room);
				}
				node = node->next;
			}
		}
	}
}

void	direct_to_start(t_hash *hash, t_room *neighbor)
{
	t_room	*next;
	t_room	*p;
	int		n;

	p = neighbor;
	n = 0;
	while (!neighbor->is_start)
	{
		next = neighbor;
		neighbor = neighbor->prev;
		if (hash_find(hash, neighbor->name))
		{
			return ;
		}
		if (!neighbor->is_start)
			neighbor->n = ++n;
	}
	neighbor = p;
	print_path(p);
	while (!neighbor->is_start)
	{
		next = neighbor;
		neighbor = neighbor->prev;
		ft_printf("di: deleting %s->%s\n", next->name, neighbor->name);
		delete_queue(&next->neighbors, neighbor);
		check_start_empty(next);
		if (!neighbor->is_start)
		{
			delete_except(neighbor, neighbor->prev, next);
			hash_insert(hash, neighbor);
		}
	}
}

int		traverse(t_hash *hash, t_queue *queue, t_room *room)
{
	t_room	*neighbor;
	int		i;

	i = 0;
	while ((neighbor = next_queue_unvisited(room->neighbors)))
	{
		if (hash_find(hash, neighbor->name))
		{
			ft_printf("found in hash");
			delete_to_start(hash, neighbor);
		}
		else
		{
			neighbor->prev = room;
			if (neighbor->is_end)
				direct_to_start(hash, neighbor);
			else
			{
				neighbor->visited = 1;
				enqueue(queue, neighbor);
			}
		}
		i++;
	}
	return (i);
}

void	unique_paths(t_room *start)
{
	t_hash	*hash;
	t_queue	*queue;
	t_room	*room;

	hash = init_hash(CAPACITY);
	queue = init_queue();
	start->visited = 1;
	enqueue(queue, start);
	while (!isempty_queue(queue))
	{
		room = dequeue(queue);
		if (!traverse(hash, queue, room))
			delete_to_start(hash, room);
		reset_queue(room->neighbors);
	}
	free_hash(hash, 0);
	free_queue(queue);
}

void	handle_start(t_hash *hash, t_queue *queue)
{
	t_room	*start;
	t_room	*next;
	int		n;
	int		i;

	start = hash->start;
	n = start->ants->size < start->neighbors->size
		? start->ants->size : start->neighbors->size;
	i = 0;
	sort_queue(start->neighbors);
	while (i < n)
	{
		next = next_queue(start->neighbors);
		print_move(move_ants(start, next), next->name, i);
		if (!next->is_end)
			enqueue(queue, next);
		i++;
	}
	if (!n)
		exit_error("no path to end");
	FP("\n");
	if (!isempty_ants(start->ants))
	{
		reset_queue(start->neighbors);
		enqueue(queue, start);
	}
}

void	algo(t_hash *hash)
{
	t_room	*room;
	t_room	*next;
	t_queue	*queue;
	int		i;
	int		n;

	queue = init_queue();
	unique_paths(hash->start);
	handle_start(hash, queue);
	while (!isempty_queue(queue))
	{
		i = -1;
		n = queue->size;
		while (++i < n)
		{
			room = dequeue(queue);
			next = next_queue(room->neighbors);
			print_move(move_ants(room, next), next->name, i);
			if (!next->is_end)
				enqueue(queue, next);
			if (!isempty_ants(room->ants))
				enqueue(queue, room);
			reset_queue(room->neighbors);
		}
		FP("\n");
	}
	free_queue(queue);
}
