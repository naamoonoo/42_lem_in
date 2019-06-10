#include "queue.h"

t_queue		*q_init(void)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

void		enqueue(t_queue *queue, void *content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->content = content;
	node->next = NULL;
	if (!queue->first)
		queue->first = node;
	else
		queue->last->next = node;
	queue->last = node;
}

void		*dequeue(t_queue *queue)
{
	t_node	*tmp;
	void	*content;

	if (queue->first)
	{
		tmp = queue->first;
		content = tmp->content;
		queue->first = tmp->next;
		free(tmp);
		if (!queue->first)
			queue->last = NULL;
		return (content);
	}
	return NULL;
}

void		*q_peek(t_queue *queue)
{
	if (queue->first)
		return (queue->first->content);
	return NULL;
}

int			q_isEmpty(t_queue *queue)
{
	if (!queue->first)
		return (1);
	return (0);
}
