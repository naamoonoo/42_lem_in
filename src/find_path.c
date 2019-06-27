#include "lem_in.h"

void	find_path(t_hash *hash)
{
	t_queue	*que;
	t_hash	*unique;
	t_room	*room;

	que = init_queue();
	unique = init_hash(CAPACITY);
	enqueue(que, hash->start);
	FP("finding path\n");
	while (que->front)
	{
		room = dequeue(que);
		FP("%s searching the path\n", room->name);
		if (room->is_end)
		{
			FP("reached to end\n");
			return ;
		}
		dup_handle(unique, room->neighbors, que);
		// if node in unique, continue
	}
	FP("no path found\n");
	free_queue(que);
	free_hash(unique);
}

void	dup_handle(t_hash *unique, t_queue *neighbor, t_queue *que)
{
	t_node	*node;

	if (!(node = neighbor->front))
		return ;
	while (node)
	{
		// FP("room %s's neighbor [%s]\n", node->room->name);
		if (!hash_find(unique, node->room->name))
		{
			hash_insert(unique, node->room);
			enqueue(que, node->room);
		}
		node = node->next;
	}
}
