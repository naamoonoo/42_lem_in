#include "lem_in.h"

void	put_ant(t_hash *hash, t_queue **paths)
{
	int ant;

	ant = 1;
	//
	hash->start->n_ant = 1;
	hash->ant_num = 1;
	//
	while (ant <= hash->ant_num || hash->end->n_ant != hash->ant_num)
	{
		push_forward(paths);
		//find_node_for_ant(paths, ant)
		print_ant(paths);
	}
}

void	push_forward(t_queue **paths)
{
	int 	idx;
	t_node	*node;
	int		tmp;

	idx = 0;
	while (paths[idx])
	{
		node = paths[idx++]->front;
		while (node && node->next)
		{
			tmp = node->next->room->n_ant;
			node->next->room->n_ant = node->room->n_ant;
			node = node->next;
		}
	}
}

void	print_ant(t_queue **paths)
{
	int 	idx;
	t_node	*node;
	int		tmp;

	idx = 0;
	while (paths[idx])
	{
		node = paths[idx++]->front;
		while (node)
		{
			FP("%dL-%s ", node->room->n_ant, node->room->name);
		}
	}
	FP("\n");
}

// void	start_ants(t_ants *ants, int n)
// {
// 	int		i;

// 	if (n < 0)
// 		exit_error("no ants cannot be negative");
// 	i = 0;
// 	while (++i <= n)
// 		add_ants(ants, i);
// }

// int		move(t_room *from, t_room *to)
// {
// 	int no;

// 	no = remove_ants(from->ants);
// 	add_ants(to->ants, no);
// 	return no;
// }

// void	print_move(int no, char *dst, int i)
// {
// 	if (i)
// 		ft_printf(" ");
// 	ft_printf("L%d-%s", no, dst);
// }
