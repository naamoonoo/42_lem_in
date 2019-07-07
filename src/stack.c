#include "lem_in.h"

t_stack *init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->top = NULL;
	return (stack);
}

t_room	*pop(t_stack *stack)
{
	t_node	*tmp;
	t_room	*room;

	if (stack->top)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		room = tmp->room;
		free(tmp);
		return (room);
	}
	return (NULL);
}

void	push(t_stack *stack, t_room *room)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->room = room;
	node->next = stack->top;
	stack->top = node;
}

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	if ((node = stack->top))
	{
		while (node)
		{
			tmp = node;
			node = node->next;
			free(tmp);
		}
	}
	free(stack);
}
