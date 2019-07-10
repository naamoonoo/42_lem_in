/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 00:05:15 by smbaabu           #+#    #+#             */
/*   Updated: 2019/07/10 01:14:17 by smbaabu          ###   ########.fr       */
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
					delete_queue(&room->neighbors, neighbor);
				node = node->next;
			}
		}
	}
}

void	handle_end(t_hash *hash, t_room *room, t_room *neighbor)
{
	neighbor->prev = room;
	direct_to_start(hash, neighbor);
}

void	visit(t_queue *queue, t_room *room, t_room *neighbor)
{
	neighbor->prev = room;
	neighbor->visited = 1;
	enqueue(queue, neighbor);
}
