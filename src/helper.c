#include "lem_in.h"

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
	room->next = NULL;
	room->connected = NULL;
	i = -1;
	while (info[++i])
		free(info[i]);
	// free(info);
	return (room);
}

void	init_connected(t_vec *v, t_room *room, t_room *neighbor)
{
	int i;

	i = 0;
	room->connected = (t_room **)malloc(sizeof(t_room *) * v->size);
	room->connected[i] = neighbor;
	while (++i < v->size)
		room->connected[i] = NULL;

}

void	print_vec(t_vec	*v)
{
	t_room *tmp = v->front;
	FP("size of vector is %d\n", v->size);
	int i;
	while (tmp)
	{
		i = -1;
		FP("%s(%d, %d) - [%s%s][", tmp->name, tmp->point.x, tmp->point.y, tmp->is_start ? "start" : "", tmp->is_end ? "end" : "");
		while (tmp->connected[++i])
			FP("%s ", tmp->connected[i]->name);
		FP("]\n");
		tmp = tmp->next;
	}
}
