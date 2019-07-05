/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:29:20 by hnam              #+#    #+#             */
/*   Updated: 2019/07/04 17:11:48 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_hash(t_hash	*hash)
{
	t_node	*n;
	t_node	*t;

	FP("number of ant : %d\n", hash->ant_num);
	for (int i = 0; i < hash->capacity; i++)
	{
		n = hash->n[i];
		while (n)
		{
			FP("[%s]-[len:%d](%d, %d) - %s%s[", n->room->name, n->room->length, n->room->point.x, n->room->point.y, n->room->is_end ? "(end)" : "", n->room->is_start ? "(start)" :"");
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
