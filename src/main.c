/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:29:25 by hnam              #+#    #+#             */
/*   Updated: 2019/07/11 23:43:32 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_hash	*hash;
	int		no;

	hash = init_hash(CAPACITY);
	no = initialize_data(hash);
	start_ants(hash->start->ants, no);
	// print_hash(hash);
	// print_rooms(hash);
	// print_links(hash);
	algo(hash);
	free_hash(hash, 1);
	// while (1);
	return (0);
}
