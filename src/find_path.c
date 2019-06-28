#include "lem_in.h"

void	bfs_algo(t_hash *hash)
{
	t_queue	*que;
	t_hash	*unique;
	t_room	*room;

	que = init_queue();
	unique = init_hash(CAPACITY);
	enqueue(que, hash->start);
	FP("start from %s\n", hash->start->name);

	while (que->front)
	{
		room = dequeue(que);
		FP("%s-", room->name);

		if (room->is_end)
		{
			FP("reached!\n");
			return ;
		}
		dup_handle_q(unique, room->neighbors, que);
		// if node in unique, continue
	}
	FP("not reached\n");
	free_queue(que);
	free_hash(unique);
}

void	dup_handle_q(t_hash *unique, t_queue *neighbor, t_queue *que)
{
	t_node	*node;

	if (!(node = neighbor->front))
		return ;
	while (node)
	{
		if (!hash_find(unique, node->room->name))
		{
			hash_insert(unique, node->room);
			enqueue(que, node->room);
		}
		node = node->next;
	}
}

// void	dfs_algo(t_room *start)
// {
// 	t_stack	*stk;
// 	t_hash	*unique;
// 	t_room	*room;
// 	// t_node	*node;

// 	stk = init_stack();
// 	unique = init_hash(CAPACITY);
// 	push(stk, start);
// 	FP("start from %s\n", start->name);
// 	while (stk->top)
// 	{
// 		room = pop(stk);
// 		FP("%s-", room->name);
// 		if (room->is_end)
// 			start->is_valid = 1;
// 		dup_handle_s(unique, room->neighbors, stk);
// 	}
// 	FP("%s\n", start->is_valid ? "reached to end" : "not reached");
// 	// node = start->neighbors->front;
// 	// while (node && node->room != start)
// 	// {
// 	// 	dfs_algo(node->room);
// 	// 	node = node->next;
// 	// }
// }
// dfs -> 구별 is_valid or not
// iterate whole node, remove non valid neighbor and node


// void	dup_handle_s(t_hash *unique, t_queue *neighbor, t_stack *stk)
// {
// 	t_node	*node;

// 	if (!(node = neighbor->front))
// 		return ;
// 	while (node)
// 	{
// 		if (!hash_find(unique, node->room->name))
// 		{
// 			hash_insert(unique, node->room);
// 			push(stk, node->room);
// 		}
// 		node = node->next;
// 	}
// }
