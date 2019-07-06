/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:29:20 by hnam              #+#    #+#             */
/*   Updated: 2019/07/05 17:14:23 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_hash(t_hash *hash)
{
	t_node	*n;
	t_node	*t;

	for (int i = 0; i < hash->capacity; i++)
	{
		n = hash->n[i];
		while (n)
		{
			FP("[%s] (%d, %d) - %s%s[", n->room->name, n->room->point.x, n->room->point.y, n->room->is_end ? "(end)" : "", n->room->is_start ? "(start)" :"");
			if (n->room->neighbors)
			{
				t = n->room->neighbors->front;
				while (t)
				{
					FP("%s ", t->room->name);
					t = t->next;
				}
			}
			FP("]\n");
			n = n->next;
		}
	}
}
