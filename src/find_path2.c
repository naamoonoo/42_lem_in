/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 00:05:15 by smbaabu           #+#    #+#             */
/*   Updated: 2019/07/11 18:02:19 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	delete_to_start(t_hash *hash, t_room *neighbor)
{
	t_room	*next;

	while (!neighbor->is_start)
	{
		next = neighbor;
		neighbor = neighbor->prev;
		if (!hash_find(hash, next->name))
		{
			delete_queue(&neighbor->neighbors, next);
			// ft_printf("ds: deleting %s -> %s\n", neighbor->name, next->name);
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
		enqueue(prev->neighbors, room);
	while (++i < n)
	{
		if ((node = room->neighbors->front))
		{
			while (node)
			{
				neighbor = node->room;
				if (neighbor != prev && neighbor != next)
				{
					// ft_printf("de: deleting %s -> %s\n", room->name, neighbor->name);
					delete_queue(&room->neighbors, neighbor);
				}
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
