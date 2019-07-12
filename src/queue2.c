/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 01:10:12 by smbaabu           #+#    #+#             */
/*   Updated: 2019/07/11 18:00:29 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*next_queue(t_queue *queue)
{
	t_node			*node;
	int				i;

	if ((node = queue->front))
	{
		i = -1;
		while (++i < queue->idx)
			node = node->next;
		queue->idx++;
	}
	return node ? node->room : NULL;
}

t_room	*next_queue_unvisited(t_queue *queue)
{
	t_room	*room;

	room = NULL;
	if (queue->front)
		while ((room = next_queue(queue)) && room->visited)
			;
	return room;
}

void	reset_queue(t_queue *queue)
{
	queue->idx = 0;
}

int		delete_queue(t_queue **queue, t_room *room)
{
	t_node	*node;
	t_node	*prev;

	if ((node = (*queue)->front))
	{
		prev = NULL;
		while (node)
		{
			if (node->room == room)
			{
				if (prev)
					prev->next = node->next;
				else
					(*queue)->front = node->next;
				if ((*queue)->idx)
					(*queue)->idx--;
				(*queue)->size--;
				free(node);
				return (1);
			}
			prev = node;
			node = node->next;
		}
	}
	return (0);
}

int		contains_queue(t_queue *queue, t_room *room)
{
	t_node	*node;

	if ((node = queue->front))
	{
		while (node)
		{
			if (node->room == room)
				return (1);
			node = node->next;
		}
	}
	return (0);
}

void	swap(t_node *a, t_node *b)
{
	t_room	*room;
	int		key;
	
	room = a->room;
	key = a->key;
	a->key = b->key;
	a->room = b->room;
	b->key = key;
	b->room = room;
}

void	sort_queue(t_queue *queue)
{
	t_node			*node;
	t_node			*i;
	t_node			*j;

	if ((node = queue->front))
	{
		i = node;
		while (i->next)
		{
			j = node;
			while (j->next)
			{
				if (j->room->n > j->next->room->n)
					swap(j, j->next);
				j = j->next;
			}
			i = i->next;
		}
	}
}