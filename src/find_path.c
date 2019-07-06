/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:36:34 by smbaabu           #+#    #+#             */
/*   Updated: 2019/07/06 13:37:05 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	all_paths(t_hash *hash, t_node **paths)
{
	
}

void	direct(t_hash *hash, t_room *from)
{
	t_queue	*queue;
	t_room	*to;
	int		i;

	i = 0;
	while (i < from->neighbors->size)
	{
		to = next(from->neighbors);
		delete_queue(to->neighbors, from);
		direct(hash, to);
		i++;
	}
}

void	preprocess(t_hash *hash)
{
	direct(hash, hash->start);
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

	queue = init_queue();
	handle_start(hash, queue);
	while (!isempty_queue(queue))
	{
		i = -1;
		while (++i < queue->size)
		{
			room = dequeue(queue);
			nextRoom = next(room->neighbors);
			no = move(room, nextRoom);
			print_move(no, nextRoom->name, i);
			if (!nextRoom->is_end)
				enqueue(queue, nextRoom);
			if (isempty_ants(room->ants))
			{
				if (room->is_start)
					reset_queue(room->neighbors);
				enqueue(queue, room);
			}
		}
		ft_printf("\n");
	}
	free_queue(queue);
}
