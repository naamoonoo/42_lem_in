/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:29:25 by hnam              #+#    #+#             */
/*   Updated: 2019/07/05 16:52:35 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_hash	*hash;

	hash = init_hash(CAPACITY);
	initialize_data(hash);
	algo(hash);
	free_hash(hash);
	return (0);
}
