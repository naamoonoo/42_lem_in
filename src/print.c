/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:29:20 by hnam              #+#    #+#             */
/*   Updated: 2019/07/12 02:30:41 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_move(int no, char *dst, int i)
{
	if (i)
		FP(" ");
	FP("L%d-%s", no, dst);
}

void	print_queue(t_queue *queue)
{
	t_node	*node;

	if ((node = queue->front))
	{
		FP("[");
		while (node)
		{
			if (node != queue->front)
				ft_putchar(' ');
			FP("%s", node->room->name);
			node = node->next;
		}
		FP("] rooms\n");
	}
}

void	print_entry(t_room *room)
{
	if (room->is_start)
		FP("##start\n");
	if (room->is_end)
		FP("##end\n");
	FP("%s %d %d\n", room->name, room->point.x, room->point.y);
}
void	print_hash(t_hash *hash)
{
	t_node	*n;
	t_node	*t;
	int		i;

	i = -1;
	while (++i < hash->capacity)
	{
		n = hash->n[i];
		while (n)
		{
			FP("[%s](%d, %d) - %s%s[", n->room->name, n->room->point.x, n->room->point.y, n->room->is_end ? "(end)" : "", n->room->is_start ? "(start)" :"");
			t = n->room->neighbors ? n->room->neighbors->front : NULL;
			while (t)
			{
				if (t->room != n->room->neighbors->front->room)
					FP(" ");
				FP("%s", t->room->name);
				t = t->next;
			}
			FP("]\n");
			n = n->next;
		}
	}
	FP("\n");
}

void	print_links(t_hash *hash)
{
	t_hash	*visited;
	t_node	*n;
	t_node	*t;
	int		i;

	visited = init_hash(CAPACITY);
	i = -1;
	while (++i < hash->capacity)
	{
		n = hash->n[i];
		while (n)
		{
			hash_insert(visited, n->room);
			if (n->room->neighbors)
			{
				t = n->room->neighbors->front;
				while (t)
				{
					if (!hash_find(visited, t->room->name))
						FP("%s-%s\n", n->room->name, t->room->name);
					t = t->next;
				}
			}
			n = n->next;
		}
	}
	free_hash(visited, 0);
	ft_printf("\n");
}

void	print_rooms(t_hash *hash)
{
	t_node	*n;
	int		i;

	i = -1;
	while (++i < hash->capacity)
	{
		n = hash->n[i];
		while (n)
		{
			print_entry(n->room);
			n = n->next;
		}
	}
}

void	print_path(t_room *end)
{
	t_room	*room;

	room = end;
	while (!room->is_start)
	{
		FP("%s<-", room->name);
		room = room->prev;
	}
	FP("start\n");
}
