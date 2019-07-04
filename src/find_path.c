#include "lem_in.h"

void	move(t_room *from, t_room *to)
{
	from->n_ant--;
	to->n_ant++;
}

int		has_ants(t_room *room)
{
	return room->n_ant > 0;
}

int print_moves(t_move *moves, int n)
{
	int i;

	i = 0;
	while (n-- > 0)
	{
		if (i)
			ft_printf(" ");
		ft_printf("L%d-%s", moves->ant, moves->dest);
	}
	ft_printf("\n");
}

void	algo(t_hash *hash)
{
	t_move	moves[CAPACITY];
	t_room	*room, *nextRoom;
	t_queue	*queue;
	int		n;
	int		count;

	queue = init_queue();
	enqueue(queue, hash->start);
	count = queue->size;
	while (!is_empty(queue))
	{
		room = dequeue(queue);
		if (!--count && !room->is_start)
			print_moves(moves, count);
		n = room->n_ant < room->neighbors->size ? room->n_ant : room->neighbors->size;
		while (n-- > 0)
		{
			nextRoom = dequeue(room->neighbors);
			move(room, nextRoom);
			if (!nextRoom->is_end)
			{
				enqueue(queue, nextRoom);
			}
		}
		if (has_ants(room))
		{
			enqueue(queue, room);
		}

	}
	free_queue(queue);
}
