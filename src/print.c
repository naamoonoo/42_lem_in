/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:29:20 by hnam              #+#    #+#             */
/*   Updated: 2019/07/10 19:34:44 by smbaabu          ###   ########.fr       */
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
		while (node)
		{
			if (node != queue->front)
				ft_putchar(' ');
			FP("%s", node->room->name);
			node = node->next;
		}
		FP(" rooms\n");
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

void	print_hash(t_hash *hash, int v)
{
	t_node	*n;
	t_node	*t;
	int		i;

	FP("%d\n", hash->start->ants->size);
	i = -1;
	while (++i < hash->capacity)
	{
		n = hash->n[i];
		while (n)
		{
			print_entry(n->room);
			if (v && n->room->neighbors)
			{
				t = n->room->neighbors->front;
				while (t)
				{
					t != n->room->neighbors->front ? FP(" ") : 0;
					FP("%s", t->room->name);
					t = t->next;
				}
			}
			n = n->next;
		}
	}
	FP("\n");
}
