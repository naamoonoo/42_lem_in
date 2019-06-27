/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:29:27 by hnam              #+#    #+#             */
/*   Updated: 2019/06/26 22:30:11 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue	*init_queue()
{
	t_queue	*queue;

	if (!(queue = (t_queue *)malloc(sizeof(t_queue))))
		return NULL;
	queue->front = NULL;
	queue->end = NULL;
	queue->size = 0;
	return (queue);
}

void	push_end(t_queue *queue, t_room *room)
{
	t_node	*node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		return ;
	node->room = room;
	node->next = NULL;
	node->key = 0;
	if (!queue->front)
	{
		queue->front = node;
		queue->end = node;
	}
	else
	{
		queue->end->next = node;
		queue->end = node;
	}
	queue->size += 1;
}

t_room	*pop_front(t_queue *queue)
{
	t_node	*tmp;
	t_room	*room;

	if (!queue->front)
		return (NULL);
	tmp = queue->front;
	while (tmp->next != queue->end)
		tmp = tmp->next;
	queue->end = tmp;
	tmp = tmp->next;
	room = tmp->room;
	queue->size -= 1;
	/* not free in here */
	return room;
}

void	free_queue(t_queue *queue)
{
	t_node	*node;
	t_node	*tmp;

	if ((node = queue->front))
	{
		while (node)
		{
			tmp = node;
			node = node->next;
			free(tmp);
		}
	}
	free(queue);
}
