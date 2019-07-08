/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:36:34 by smbaabu           #+#    #+#             */
/*   Updated: 2019/07/07 17:08:31 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	make_directed(t_hash *hash, t_room *from)
{
	t_room	*to;
	int		i;

	i = 0;
	while (i < from->neighbors->size)
	{
		to = next(from->neighbors);
		ft_printf("from %s -> to %s\n", from->name, to->name);
		delete_queue(&to->neighbors, from);
		if (!to->is_end)
			make_directed(hash, to);
		i++;
	}
	reset_queue(from->neighbors);
}

void	unique_paths(t_room *room, t_hash *visited)
{
	t_room	*neighbor;
	int		i;
	int		n;

	n = room->neighbors->size;
	i = 0;
	while (i < n)
	{
		neighbor = next(room->neighbors);		
		if (hash_find(visited, neighbor->name))
		{
			delete_queue(&room->neighbors, neighbor);
		}
		else if (!neighbor->is_end)
		{
			hash_insert(visited, neighbor);
			unique_paths(neighbor, visited);
		}
		i++;
	}
	reset_queue(room->neighbors);
}

void	preprocess(t_hash *hash)
{
	t_hash	*visited;

	make_directed(hash, hash->start);
	visited = init_hash(CAPACITY);
	unique_paths(hash->start, visited);
	// ft_printf("\n");
	// print_hash(visited);
	// ft_printf("\n");
	// print_hash(hash);
	// free_hash(visited);
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
		nextRoom = next(startRoom->neighbors);
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
	preprocess(hash);
	handle_start(hash, queue);
	while (!isempty_queue(queue))
	{
		i = -1;
		// print_queue(queue);
		n = queue->size;
		while (++i < n)
		{
			room = dequeue(queue);
			nextRoom = next(room->neighbors);
			// ft_printf("nextRoom %s for %s\n", nextRoom->name, room->name);
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
	// free_queue(queue);
}
