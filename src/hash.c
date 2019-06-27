#include "lem_in.h"

t_hash	*init_hash(int capacity)
{
	t_hash	*hash;
	int		i;

	if(!(hash = (t_hash *)malloc(sizeof(t_hash))))
		return (NULL);
	if (!(hash->n = (t_node **)malloc(sizeof(t_node *) * capacity)))
		return (NULL);
	i = 0;
	while (i < capacity)
		hash->n[i++] = NULL;
	hash->capacity = capacity;
	return (hash);
}

int		get_hash(char *key, int capacity)
{
	int	res;
	int	i;

	i = -1;
	res = 0;
	while (key[++i])
		res = (int)key[i] * i;
	return (res % capacity);
}

void	hash_insert(t_hash *hash, t_room *room)
{
	t_node	*node;
	t_node	*tmp;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		return ;
	node->key = get_hash(room->name, hash->capacity);
	node->room = room;
	node->next = NULL;
	if (!hash->n[node->key])
		hash->n[node->key] = node;
	else
	{
		tmp = hash->n[node->key];
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

t_room	*hash_find(t_hash *hash, char *key)
{
	int		k;
	t_node	*node;

	k = get_hash(key, hash->capacity);
	node = hash->n[k];
	if (!ft_strcmp(node->room->name, key))
		return (node->room);
	while ((node = node->next))
		if (!ft_strcmp(node->room->name, key))
			return (node->room);
}

void	free_hash(t_hash *hash)
{
	int		i;
	t_node	*tmp;
	t_node	*node;

	i = -1;
	while (hash->n[++i])
	{
		node = hash->n[i];
		while (node)
		{
			free(node->room->name);
			// free(tmp->room->neighbors);
			free(node->room);
			tmp = node;
			node = node->next;
			free(tmp);
		}
		free(hash->n[i]);
	}
	free(hash->n);
	free(hash);
}
