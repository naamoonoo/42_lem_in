/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:29:20 by hnam              #+#    #+#             */
/*   Updated: 2019/07/10 00:44:46 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	exit_error(char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(1);
}

void	print_move(int no, char *dst, int i)
{
	if (i)
		ft_printf(" ");
	ft_printf("L%d-%s", no, dst);
}

void	print_entry(t_room *room)
{
	FP("[%s] (%d, %d) - %s%s[", room->name, room->point.x, room->point.y,
		room->is_end ? "(end)" : "", room->is_start ? "(start)" : "");
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
			print_entry(n->room);
			if (n->room->neighbors)
			{
				t = n->room->neighbors->front;
				while (t)
				{
					t != n->room->neighbors->front ? FP(" ") : 0;
					FP("%s", t->room->name);
					t = t->next;
				}
			}
			FP("]\n");
			n = n->next;
		}
	}
}
