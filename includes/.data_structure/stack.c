// #include "stack.h"

// t_stack *s_init(void)
// {
// 	t_stack	*stack;

// 	stack = (t_stack *)malloc(sizeof(t_stack));
// 	stack->top = NULL;
// 	return (stack);
// }

// void	*pop(t_stack *stack)
// {
// 	t_node	*tmp;
// 	void			*content;

// 	if (stack->top)
// 	{
// 		tmp = stack->top;
// 		stack->top = stack->top->next;
// 		content = tmp->content;
// 		free(tmp);
// 		return (content);
// 	}
// 	return (NULL);
// }

// void	push(t_stack *stack, void *content)
// {
// 	t_node	*node;

// 	node = (t_node *)malloc(sizeof(t_node));
// 	node->content = content;
// 	node->next = stack->top;
// 	stack->top = node;
// }

// void	*s_peek(t_stack *stack)
// {
// 	if (stack->top)
// 		return (stack->top->content);
// 	return (NULL);
// }

// int		s_isEmpty(t_stack *stack)
// {
// 	if (stack->top)
// 		return (0);
// 	return (1);
// }
