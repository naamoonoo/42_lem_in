#include "lem_in.h"

/*
** info
* front - access first data
* end - access last data
* size - get the size of vector
* empty - check is empty
* get - access by index

** modifier
* init
* push_back - Add element at the end
* pop_back - Delete last element
* insert - Insert elements
* erase - Erase elements
*/

// t_room	*front(t_vec *v)
// {
// 	return v->front;
// }

// t_room	*end(t_vec *v)
// {
// 	return v->end;
// }


t_room	*get(t_vec *v, int idx)
{
	t_room	*room;

	room = v->front;
	while (idx-- > 0)
		room = room->next;
	return room;
}

t_room	*get_by_name(t_vec *v, char *name)
{
	t_room	*room;

	room = v->front;
	while (ft_strcmp(room->name, name))
		room = room->next;
	return room;
}

int		empty(t_vec *v)
{
	return (v->size == 0);
}

int		size(t_vec *v)
{
	return (v->size);
}
