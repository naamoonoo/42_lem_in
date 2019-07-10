/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 22:30:04 by smbaabu           #+#    #+#             */
/*   Updated: 2019/07/09 22:30:40 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	mark_unvisited(t_hash *hash)
{
	t_node	*node;
	int		i;

	i = -1;
	while (++i < hash->capacity)
	{
		node = hash->n[i];
		while (node)
		{
			node->room->visited = 0;
			node = node->next;
		}
	}
}

void	print_map(t_hash *hash)
{
	t_node *node;
	t_room *neighbor;
	t_room *room;
	t_queue *queue;
	
	queue = init_queue();
	mark_unvisited(hash);
	enqueue(queue, hash->start);
	hash->start->visited = 1;
	while (!isempty_queue(queue))
	{
		room = dequeue(queue);
		ft_printf("deque %s\n", room->name);
		if ((node = room->neighbors->front))
		{
			while (node)
			{
				neighbor = node->room;
				if (!neighbor->visited)
				{
					neighbor->visited = 1;
					enqueue(queue, neighbor);
					ft_printf("enqueue %s\n", neighbor->name);
				}
				node = node->next;
			}
		}
	}
}