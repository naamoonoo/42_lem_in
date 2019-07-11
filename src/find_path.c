/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:36:34 by smbaabu           #+#    #+#             */
/*   Updated: 2019/07/10 17:38:57 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	direct_to_start(t_hash *hash, t_room *neighbor)
{
	t_room	*next;
	int		n;

	n = 0;
	while (!neighbor->is_start)
	{
		next = neighbor;
		neighbor = neighbor->prev;
		if (hash_find(hash, neighbor->name))
			return ;
		if (!neighbor->is_start)
		{
			delete_except(neighbor, neighbor->prev, next);
			hash_insert(hash, neighbor);
		}
		delete_queue(&next->neighbors, neighbor);
		n++;
		if (!neighbor->is_start)
			neighbor->n = n;
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
			delete_to_start(neighbor);
		else if (neighbor->is_end)
			handle_end(hash, room, neighbor);
		else
			visit(queue, room, neighbor);
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
			delete_to_start(room);
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
