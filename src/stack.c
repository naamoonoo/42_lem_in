// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   stack.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2019/06/27 12:30:54 by hnam              #+#    #+#             */
// /*   Updated: 2019/06/27 12:33:31 by hnam             ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "lem_in.h"

// t_stack	*init_stack()
// {
// 	t_stack	*stack;

// 	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
// 		return NULL;
// 	stack->top = NULL;
// 	return (stack);
// }

// void	push(t_stack *stack, t_room *room)
// {
// 	t_node	*node;

// 	if (!(node = (t_node *)malloc(sizeof(t_node))))
// 		return ;
// 	node->room = room;
// 	node->next = NULL;
// 	node->key = 0;
// 	if (stack->top)
// 		stack->top->next = node;
// 	stack->top = node;
// }

// t_room	*pop(t_stack *stack)
// {
// 	t_node	*tmp;
// 	t_room	*room;

// 	if (!(tmp = stack->top))
// 		return (NULL);
// 	stack->top = tmp->next;
// 	room = tmp->room;
// 	free(tmp);
// 	return (room);
// }

// void	free_stack(t_stack *stack)
// {
// 	t_node	*node;
// 	t_node	*tmp;

// 	if ((node = stack->top))
// 	{
// 		while (node)
// 		{
// 			tmp = node;
// 			node = node->next;
// 			free(tmp);
// 		}
// 	}
// 	free(stack);
// }
