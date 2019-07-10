/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 00:42:11 by smbaabu           #+#    #+#             */
/*   Updated: 2019/07/10 01:45:17 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	start_ants(t_ants *ants, int n)
{
	int		i;

	if (n < 0)
		exit_error("no ants cannot be negative");
	if (n > CAPACITY)
		exit_error("ants greater than capacity");
	i = 0;
	while (++i <= n)
		add_ants(ants, i);
}

int		move_ants(t_room *from, t_room *to)
{
	int no;

	no = remove_ants(from->ants);
	add_ants(to->ants, no);
	return (no);
}

void	swap(t_node *a, t_node *b)
{
	t_room	*room;
	int		key;
	
	room = a->room;
	key = a->key;
	a->key = b->key;
	a->room = b->room;
	b->key = key;
	b->room = room;
}

void	sort_queue(t_queue *queue)
{
	t_node			*node;
	t_node			*i;
	t_node			*j;

	if ((node = queue->front))
	{
		i = node;
		while (i->next)
		{
			j = node;
			while (j->next)
			{
				if (j->room->n > j->next->room->n)
					swap(j, j->next);
				j = j->next;
			}
			i = i->next;
		}
	}
}