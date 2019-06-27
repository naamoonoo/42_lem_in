#include "lem_in.h"

int		initialize_data(t_hash *hash, int fd)
{
	char	*line;
	int		is_start;
	int		is_ant_num;

	line = NULL;
	is_ant_num = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
		{
			is_start = ft_strcmp(line, "##start") == 0 ? 1 : 0;
			free(line);
			get_next_line(fd, &line);
			is_start ? add_room(v, line, 1, 0) : add_room(v, line, 0, 1);
		}
		else if (ft_strchr(line, '#'))
			FP("[comment] %s\n", line);
		else if (ft_strchr(line, ' '))
			add_room(v, line, 0, 0);
		else if (ft_strchr(line, '-'))
			break;
			// add_neighbor(v, line);
		free(line);
	}
	print_hash(v);
	return (0);
}
/*
* int	read_data(char *line)
*
* number_of_ants -> first line
* comments -> start with #
* start/end point -> start with ## and start/end
* room -> name loc_x lox_y (3 information seperated with space)
* link -> two rooms name is connected with '-'
*/

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
void	add_room(t_hash *hash, char *line, int is_start, int is_end)
{
	t_room	*room;

	// if (ft_strchr(line, ' '))
	room = init_room(line, is_start, is_end);
	if (is_start)
		insert(v, room);
	else
		push_back(v, room);
}

void	add_neighbor(t_hash *hash, char *line)
{
	t_room	*room;
	t_room	*neigbor;
	char	**names;
	int		i;

	names = ft_strsplit(line, '-');
	if (!(room = get_by_name(v, names[0])))
		return ;
	if (!(neigbor = get_by_name(v, names[1])))
		return ;
	if (!room->connected)
		init_connected(v, room, neigbor);
	else if (!check_existed(room, neigbor->name))
	{
		i = 0;
		while (room->connected[i])
			i++;
		room->connected[i] = neigbor;
	}
	i = -1;
	while (names[++i])
		free(names[i]);
	free(names);
}

// void	add_neighbor(t_hash *hash, char *line)
// {
// 	t_room	*room;
// 	t_room	*neighbor;
// 	char	**names;
// 	int		i;

// 	names = ft_strsplit(line, '-');
// 	room = get_by_name(v, names[0]);
// 	neighbor = ft_memalloc(sizeof(t_room));
// 	if (!room->neighbors)
// 	{
// 		FP("room[%s]'s neighbor is empty\n", room->name);
// 		init_hashtor(room->neighbors);
// 		// push_back(room->neighbors, neighbor);
// 		// room->neighbors = (t_hash *)malloc(sizeof(t_hash));
// 		// room->neighbors->front = neighbor;
// 		// room->neighbors->end = neighbor;
// 	}
// 	// elsm
// 	FP("try to add neighbor[%s]\n", neighbor->name);
// 		push_back(room->neighbors, neighbor);
// 	// else
// 	// {
// 	// 	room->neighbors->end->next = neighbor;
// 	// 	room->neighbors->end = neighbor;
// 	// }
// 	i = -1;
// 	while (names[++i])
// 		free(names[i]);
// 	free(names);
// }

