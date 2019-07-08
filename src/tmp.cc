#include "lem-in.h"

void	unique_paths(t_room *room, t_hash *visited)
{
	t_room	*neighbor;
	int		i;
	int		n;

	n = room->neighbors->size;
	i = 0;
	while (i < n)
	{
		neighbor = next(room->neighbors);		
		if (hash_find(visited, neighbor->name))
		{
			delete_queue(&room->neighbors, neighbor);
		}
		else if (!neighbor->is_end)
		{
			hash_insert(visited, neighbor);
			unique_paths(neighbor, visited);
		}
		i++;
	}
	reset_queue(room->neighbors);
}

void	preprocess(t_hash *hash)
{
	t_hash	*visited;

	make_directed(hash, hash->start);
	visited = init_hash(CAPACITY);
	unique_paths(hash->start, visited);
}

void	make_directed(t_hash *hash, t_room *from)
{
	t_room	*to;
	int		i;

	i = 0;
	while (i < from->neighbors->size)
	{
		to = next(from->neighbors);
		ft_printf("from %s -> to %s\n", from->name, to->name);
		delete_queue(&to->neighbors, from);
		if (!to->is_end)
			make_directed(hash, to);
		i++;
	}
	reset_queue(from->neighbors);
}

void	make_directed(t_node *node)
{
	t_queue	*queue;
	t_room	*room;
	t_room	*neighbor;
	int		i;
	int		n;

	queue = init_queue();
	node->room->visited = 1;
	enqueue(queue, node->room);
	while (!isempty_queue(queue))
	{
		room = dequeue(queue);
		n = room->neighbors->size;
		i = -1;
		while (++i < n)
		{
			neighbor = next(room->neighbors);
			if (!neighbor->visited)
			{
				neighbor->visited = 1;
				enqueue(queue, neighbor);
			}
			else
			{
				delete_queue(&room->neighbors, neighbor);
			}
		}
		reset_queue(room->neighbors);
	}
	free_queue(queue);
}