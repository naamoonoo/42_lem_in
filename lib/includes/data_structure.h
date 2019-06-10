/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structure.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 23:17:45 by hnam              #+#    #+#             */
/*   Updated: 2019/06/09 23:37:51 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCTURE_H
# define DATA_STRUCTURE_H

# include <stdlib.h>

# include "queue.h"
# include "stack.h"

typedef struct	s_node
{
	void		*content;
	t_node		*next;
}				t_node;

#endif
