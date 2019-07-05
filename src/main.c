/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:29:25 by hnam              #+#    #+#             */
/*   Updated: 2019/07/04 17:15:59 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main()
{
	t_hash *hash;

	hash = init_hash(CAPACITY);
	initialize_data(hash);

	// path_counter(hash->start);
	print_hash(hash);

	bfs_algo(hash);
	// bfs_algo(hash);
	// dfs_algo(hash->start);
	free_hash(hash, 1);

	// while(1)
	// 	sleep(1);
	return (0);
}
