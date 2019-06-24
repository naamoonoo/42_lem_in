#include "lem_in.h"

int		initialize_data(t_vec *v, int fd)
{
	char	*line;
	int		is_start;
	int		is_end;
	int		is_ant_num;

	line = NULL;
	is_ant_num = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strchr(line, '#'))
		{
			is_start = !ft_strcmp(line, "##start") ? 1 : 0;
			is_end = !ft_strcmp(line, "##end") ? 1 : 0;
			FP("%s\n", line);
		}
		else if (ft_strchr(line, ' '))
			add_room(v, line, &is_start, &is_end);
		else if (ft_strchr(line, '-'))
			add_neighbor(v, line);
		free(line);
	}
	print_vec(v);
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
void	add_room(t_vec *v, char *line, int *is_start, int *is_end)
{
	t_room	*room;

	if (ft_strchr(line, ' '))
		room = init_room(line, *is_start, *is_end);
	if (*is_start)
		insert(v, room);
	else
		push_back(v, room);
	*is_start = 0;
	*is_end = 0;
}

void	add_neighbor(t_vec *v, char *line)
{
	t_room	*room;
	t_room	*neigbor;
	char	**names;
	int		i;

	names = ft_strsplit(line, '-');
	room = get_by_name(v, names[0]);
	neigbor = get_by_name(v, names[1]);
	if (!room->connected)
		init_connected(v, room, neigbor);
	else
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
