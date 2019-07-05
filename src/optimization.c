// #include "lem_in.h"

// void	path_counter(t_room *room)
// {
// 	t_node	*nb;

// 	if (room->is_end)
// 		return ;
// 	if (room->neighbors && (nb = room->neighbors->front))
// 	{
// 		while (nb)
// 		{
// 			path_counter(nb->room);
// 			if (nb->room->is_end)
// 				room->length = 1;
// 			nb = nb->next;
// 		}
// 	}
// }

// void	bfs_algo(t_hash *hash)
// {
// 	t_queue	*que;
// 	t_hash	*unique;
// 	t_room	*room;

// 	que = init_queue();
// 	unique = init_hash(CAPACITY);
// 	enqueue(que, hash->start);
// 	hash_insert(unique, hash->start);
// 	FP("start from %s\n", hash->start->name);
// 	while (que->front)
// 	{
// 		room = dequeue(que);
// 		FP("%s-", room->name);
// 		if (room->is_end)
// 			break;
// 		dup_handle_q(unique, room->neighbors, que);
// 	}
// 	room->is_end ? FP("reached\n") : FP("not reached\n");
// 	free_queue(que);
// 	free_hash(unique, 0);
// }

// void	dup_handle_q(t_hash *unique, t_queue *neighbor, t_queue *que)
// {
// 	t_node	*node;

// 	if (!(node = neighbor->front))
// 		return ;
// 	while (node)
// 	{
// 		if (!hash_find(unique, node->room->name))
// 		{
// 			hash_insert(unique, node->room);
// 			enqueue(que, node->room);
// 		}
// 		node = node->next;
// 	}
// }
