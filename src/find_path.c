/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:36:34 by smbaabu           #+#    #+#             */
/*   Updated: 2019/07/08 14:20:36 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		all_paths(t_room *start, t_queue **paths)
{
	t_queue	*queue;

	queue = init_queue();
	enqueue(queue, start);

	while (isempty_ants())
	{

	}
}

t_queue				***group_paths(t_queue **t_queue);

t_hash				*select_paths(t_queue ***group_of_paths);

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
		n = queue->size;
		while (++i < n)
		{
			room = dequeue(queue);
			nextRoom = next(room->neighbors);
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
