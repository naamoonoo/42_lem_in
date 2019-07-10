/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:29:25 by hnam              #+#    #+#             */
/*   Updated: 2019/07/10 01:20:51 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_hash	*hash;
	int		no;

	hash = init_hash(CAPACITY);
	// print_hash(hash);
	no = initialize_data(hash);
	start_ants(hash->start->ants, no);
	algo(hash);
	free_hash(hash, 1);
	// free_ants(hash->start);
	return (0);
}
