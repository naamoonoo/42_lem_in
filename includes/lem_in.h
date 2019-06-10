/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:31:49 by hnam              #+#    #+#             */
/*   Updated: 2019/06/09 23:32:21 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../lib/includes/ft_printf.h"
# include "../lib/includes/libft.h"
# include "../lib/includes/data_structure.h"

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_room
{
	char			*name;
	t_point			point;
	int				is_start;
	int				is_end;
	int				n_ant;
	char			*connected;
	struct s_room	*next;
}					t_room;

typedef struct		s_lem_in
{
	int				n_ants;
	t_room			*rooms;
	char			*passed;

}					t_li;

int					initialize_data(t_li *t_l);
int					read_data(char *line);

#endif
