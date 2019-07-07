/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:29:29 by hnam              #+#    #+#             */
/*   Updated: 2019/07/06 21:06:12 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
* int	initialize_data(t_hash *hash)
*
* number_of_ants -> first line
* comments -> start with #
* start/end point -> start with ## and start/end
* room -> name loc_x lox_y (3 information seperated with space)
* link -> two rooms name is connected with '-'
*/

int		initialize_data(t_hash *hash)
{
	char	*line;
	int		is_start;

	line = NULL;
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
		{
			is_start = ft_strcmp(line, "##start") == 0 ? 1 : 0;
			free(line);
			get_next_line(STDIN_FILENO, &line);
			is_start ? add_room(hash, line, 1, 0) : add_room(hash, line, 0, 1);
		}
		else if (!hash->ant_num && (int)ft_strlen(line) == ft_numlen(ft_atoi(line), 10))
			hash->ant_num = ft_atoi(line);
		else if (ft_strchr(line, '#'))
			FP("[comment] %s\n", line);
		else if (ft_strchr(line, ' '))
			add_room(hash, line, 0, 0);
		else if (ft_strchr(line, '-'))
			add_neighbor(hash, line);
		free(line);
	}

	return (0);
}
/*
**Input Redirection (" < ")
*
*Just as the output of a command can be redirected to a
*file, the less-than character < is used to redirect the
*input of a command.
*
*Instead of open the files as an argument, redirected file
*is automatically opened and comes as standard input. so,
*just read the standard input is enough
*https://www.tutorialspoint.com/unix/unix-io-redirections.htm
*/

t_room	*init_room(char *line, int is_start, int is_end)
{
	t_room	*room;
	char	**info;
	int		i;

	if(!(room = (t_room *)malloc(sizeof(t_room))))
		return NULL;
	info = ft_strsplit(line, ' ');
	room->name = ft_strdup(info[0]);
	room->point.x = ft_atoi(info[1]);
	room->point.y = ft_atoi(info[2]);
	room->is_start = is_start;
	room->is_end = is_end;
	room->is_valid = 0;
	room->neighbors = NULL;
	room->length = 0;
	room->prev = NULL;
	i = -1;
	while (info[++i])
		free(info[i]);
	free(info);
	return (room);
}

void	add_room(t_hash *hash, char *line, int is_start, int is_end)
{
	t_room	*room;

	room = init_room(line, is_start, is_end);
	hash_insert(hash, room);
	if (is_start)
		hash->start = room;
	if (is_end)
		hash->end = room;
}

void	add_neighbor(t_hash *hash, char *line)
{
	t_room	*room;
	t_room	*neighbor;
	char	**names;
	int		i;

	names = ft_strsplit(line, '-');
	room = hash_find(hash, names[0]);
	neighbor = hash_find(hash, names[1]);
	if (!room || !neighbor || room == neighbor)
		return ;
	if (!room->neighbors)
		room->neighbors = init_queue();
	enqueue_neighbor(room, neighbor);
	i = -1;
	while (names[++i])
		free(names[i]);
	free(names);
}

void	enqueue_neighbor(t_room *room, t_room *neighbor)
{
	t_node	*tmp;

	if (!room->neighbors)
		room->neighbors = init_queue();
	tmp = room->neighbors->front;
	while (tmp)
	{
		if (tmp->room == neighbor)
			return ;
		tmp = tmp->next;
	}
	enqueue(room->neighbors, neighbor);
	if (!neighbor->neighbors)
		neighbor->neighbors = init_queue();
	tmp = neighbor->neighbors->front;
	while (tmp)
	{
		if (tmp->room == room)
			return ;
		tmp = tmp->next;
	}
	enqueue(neighbor->neighbors, room);
}
