#include "lem_in.h"

t_queue	**get_paths(t_hash *hash)
{
	t_queue	**paths;

	t_node	*start;
	int		idx;

	if (!(paths = (t_queue **)malloc(sizeof(t_queue *)
		* hash->start->neighbors->size)))
		return (NULL);
	idx = 0;
	hash->start->length = 0;
	start = hash->start->neighbors->front;
	while (idx < hash->start->neighbors->size)
	{
		hash_default_set(hash);
		paths[idx++] = find_path(hash, hash->start);
		// hash_default_set(hash);
		// start->room->prev = hash->start;
		// start->room->length = 1;
		// paths[idx++] = find_path(hash, start->room);
		// start = start->next;

	}
	return (paths);
}

t_queue	*find_path(t_hash *hash, t_room *start)
{
	t_queue	*que;
	t_hash	*unique;
	t_room	*room;

	que = init_queue();
	unique = init_hash(hash->size);
	enqueue(que, start);
	hash_insert(unique, start);
	while (que->front)
	{
		room = dequeue(que);
		daijkstra(unique, room->neighbors, que, room);
	}
	free_queue(que);
	free_hash(unique, 0);
	return path_make(hash);
}

void	daijkstra(t_hash *unique, t_queue *neighbor, t_queue *que, t_room *parent)
{
	t_node	*node;

	if (!(node = neighbor->front))
		return ;
	while (node)
	{
		if (!hash_find(unique, node->room->name)
			&& node->room->length >= parent->length + 1 &&
			node->room->is_valid == 0 &&
			node->room->length != 1)
		{
			node->room->length = parent->length + 1;
			node->room->prev = parent;
			node->room->is_end ? 0 : hash_insert(unique, node->room);
			enqueue(que, node->room);
		}
		/*
		** node not in start's neighbor
		** node not in unique
		** node's length > parent's node + 1
		** ====> node->prev = parent && length = parent->length + 1
		*/
		node = node->next;
	}
}

t_queue	*path_make(t_hash *hash)
{
	t_stack	*stk;
	t_queue	*que;
	t_room	*room;

	if (!hash->end->prev)
		return (NULL);
	stk = init_stack();
	que = init_queue();
	push(stk, hash->end);
	while (stk->top->room != hash->start)
		push(stk, stk->top->room->prev);
	while (stk->top)
	{
		room = pop(stk);
		room->is_end ? 0 : (room->is_valid = 1);
		enqueue(que, room);
	}


	//
	t_node	*node = que->front;
	FP("[len : %d]\t", que->size);
	while (node)
	{
		FP("%s ", node->room->name);
		node = node->next;
	}
	FP("\n");
	//
	return (que);
}
