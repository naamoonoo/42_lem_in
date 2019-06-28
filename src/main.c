/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:29:25 by hnam              #+#    #+#             */
/*   Updated: 2019/06/27 19:44:26 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main()
{
	t_hash *hash;

	hash = init_hash(CAPACITY);
	initialize_data(hash);

	bfs_algo(hash);
	// dfs_algo(hash->start);
	free_hash(hash);
	return (0);
}
