/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:29:25 by hnam              #+#    #+#             */
/*   Updated: 2019/07/07 00:06:19 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main()
{
	t_hash	*hash;
	t_queue	**paths;
	int		idx;

	hash = init_hash(CAPACITY);
	initialize_data(hash);

//
	print_hash(hash);
//
	paths = get_paths(hash);

	idx = 0;
	// while (idx < hash->size && paths[idx])
	// 	free_queue(paths[idx++]);
	// free(paths);
	free_hash(hash, 1);

	// while(1)
	// 	sleep(1);
	return (0);
}
