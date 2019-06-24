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

t_vec	*init_vector()
{
	t_vec	*vec;

	if(!(vec = (t_vec *)malloc(sizeof(t_vec))))
		return NULL;
	vec->front = NULL;
	vec->end = NULL;
	vec->size = 0;
	return vec;
}

void	push_back(t_vec *v, t_room *room)
{
	if (empty(v))
	{
		v->front = room;
		v->end = room;
	}
	else
	{
		v->end->next = room;
		v->end = room;
	}
	v->size += 1;
}

t_room	*pop_back(t_vec *v)
{
	t_room	*tmp;

	if (empty(v))
		return NULL;
	tmp = v->end;
	v->end = get(v, v->size - 2);
	v->size -= 1;
	/* not free in here */
	return tmp;
}

void	insert(t_vec *v, t_room *room)
{
	if (empty(v))
	{
		v->front = room;
		v->end = room;
	}
	else
	{
		room->next = v->front;
		v->front = room;
	}
	v->size += 1;
}

t_room	*erase(t_vec *v)
{
	t_room	*tmp;

	if (empty(v))
		return NULL;
	tmp = v->front;
	v->front = tmp->next;
	if (!v->front)
		v->end = NULL;
	v->size -= 1;
	/* not free in here */
	return tmp;
}

