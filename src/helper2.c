/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 17:14:30 by smbaabu           #+#    #+#             */
/*   Updated: 2019/07/05 20:17:19 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	exit_error(char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(1);
}

void	start_ants(t_ants *ants, int n)
{
	int		i;

	if (n < 0)
		exit_error("no ants cannot be negative");
	i = 0;
	while (++i <= n)
		add_ants(ants, i);
}

int		move(t_room *from, t_room *to)
{
	int no;

	no = remove_ants(from->ants);
	add_ants(to->ants, no);
	return no;
}

void	print_move(int no, char *dst, int i)
{
	if (i)
		ft_printf(" ");
	ft_printf("L%d-%s", no, dst);
}
