/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:29:20 by hnam              #+#    #+#             */
/*   Updated: 2019/07/07 00:50:09 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_hash(t_hash *hash)
{
	t_node	*n;
	t_node	*t;

	FP("number of ant : %d\n", hash->ant_num);
	for (int i = 0; i < hash->capacity; i++)
	{
		n = hash->n[i];
		while (n)
		{
			FP("[%s](%d, %d) - %s%s[", n->room->name, n->room->point.x, n->room->point.y, n->room->is_end ? "(end)" : "", n->room->is_start ? "(start)" :"");
			t = n->room->neighbors ? n->room->neighbors->front : NULL;
			while (t)
			{
				FP("%s ", t->room->name);
				t = t->next;
			}
			FP("]\n");
			n = n->next;
		}
	}
}

void	hash_default_set(t_hash *hash)
{
	t_node	*n;
	int		i;

	i = -1;
	while (++i < hash->capacity)
	{
		n = hash->n[i];
		while (n)
		{
			n->room->length = INT_MAX;
			n->room->prev = NULL;
			n = n->next;
		}
	}
}

int		is_error(t_hash *hash)
{
	int error;

	error = 0;
	if (!hash->size || !hash->ant_num || !hash->start || !hash->end)
		error = 1;
	if (!bfs_algo(hash))
		error = 1;
	if (error)
		FP("ERROR\n");
	return (error);
}
