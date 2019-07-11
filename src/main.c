/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:29:25 by hnam              #+#    #+#             */
/*   Updated: 2019/07/10 23:19:27 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_hash	*hash;
	int		no;

	hash = init_hash(CAPACITY);
	no = initialize_data(hash);
	hash->start->ants = init_ants();
	start_ants(hash->start->ants, no);
	// print_rooms(hash);
	// print_links(hash);
	algo(hash);
	// free_hash(hash, 1);
	return (0);
}
