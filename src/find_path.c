/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:36:34 by smbaabu           #+#    #+#             */
/*   Updated: 2019/07/09 22:31:02 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	delete_to_start(t_room *neighbor)
{
	t_room	*next;

	while (!neighbor->is_start)
	{
		next = neighbor;
		neighbor = neighbor->prev;
		delete_queue(&neighbor->neighbors, next);
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
	while (++i < n)
	{
		if ((node = room->neighbors->front))
		{
			while (node)
			{
				neighbor = node->room;
				if (neighbor != prev && neighbor != next)
				{
					// ft_printf("deleting %s from %s\n", neighbor->name, room->name);
					delete_queue(&room->neighbors, neighbor);
				}
				node = node->next;
			}
		}
	}
}

void	direct_to_start(t_hash *hash, t_room *neighbor)
{
	t_room	*next;
	int		n;

	n = 0;
	while (!neighbor->is_start)
	{
		next = neighbor;
		neighbor = neighbor->prev;
		// ft_printf("%s<-%s\n", neighbor->name, next->name);
		if (hash_find(hash, neighbor->name))
			return ;
		if (!neighbor->is_start)
			delete_except(neighbor, neighbor->prev, next);
		if (!neighbor->is_start)
			hash_insert(hash, neighbor);
		delete_queue(&next->neighbors, neighbor);
		n++;
		if (!neighbor->is_start)
			neighbor->n = n;
	}
}

void	unique_paths(t_room *start)
{
	t_hash	*hash;
	t_queue	*queue;
	t_room	*neighbor;
	t_room	*room;
	int		i;

	hash = init_hash(CAPACITY);
	queue = init_queue();
	start->visited = 1;
	enqueue(queue, start);
	while (!isempty_queue(queue))
	{
		room = dequeue(queue);
		i = 0;
		while ((neighbor = next_queue_unvisited(room->neighbors)))
		{
			if (hash_find(hash, neighbor->name))
				delete_to_start(neighbor);
			else if (neighbor->is_end)
			{
				neighbor->prev = room;
				direct_to_start(hash, neighbor);
			}
			else
			{
				neighbor->prev = room;
				neighbor->visited = 1;
				enqueue(queue, neighbor);
			}
			i++;
		}
		if (!i)
			delete_to_start(room);
		reset_queue(room->neighbors);
	}
}

void	handle_start(t_hash *hash, t_queue *queue)
{
	t_room	*startRoom;
	t_room	*nextRoom;
	int		no;
	int		n;
	int		i;

	startRoom = hash->start;
	n = startRoom->ants->size < startRoom->neighbors->size
		? startRoom->ants->size : startRoom->neighbors->size;
	i = 0;
	while (i < n)
	{
		nextRoom = next_queue(startRoom->neighbors);
		no = move(startRoom, nextRoom);
		print_move(no, nextRoom->name, i);
		if (!nextRoom->is_end)
			enqueue(queue, nextRoom);
		i++;
	}
	ft_printf("\n");
	if (!isempty_ants(startRoom->ants))
	{
		reset_queue(startRoom->neighbors);
		enqueue(queue, startRoom);
	}
}

void	algo(t_hash *hash)
{
	t_room	*room;
	t_room	*nextRoom;
	t_queue	*queue;
	int		i;
	int		no;
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
			nextRoom = next_queue(room->neighbors);
			no = move(room, nextRoom);
			print_move(no, nextRoom->name, i);
			if (!nextRoom->is_end)
				enqueue(queue, nextRoom);
			if (!isempty_ants(room->ants))
				enqueue(queue, room);
			reset_queue(room->neighbors);
		}
		ft_printf("\n");
	}
}
