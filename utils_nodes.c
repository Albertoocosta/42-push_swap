/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:00:43 by cda-fons          #+#    #+#             */
/*   Updated: 2024/10/01 17:35:21 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_node	*create_node(int content)
{
	t_node *node;

	node = (t_node *) malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->nbr = content;
	node->next = NULL;
	node->target = NULL;
	node->prev = NULL;
	return (node);
}
t_node	*add_node_to_list(t_node *node, int content)
{
	t_node	*new_node;
	
	new_node = create_node(content);
	if (!new_node)
		return (NULL);
	if (!node)
		return (new_node);
	node->next = new_node;
	new_node->prev = node;
	return (new_node);
}
int	stacklen(t_node *node)
{
	int	i;

	i = 0;
	if (!node)
	{
		return (0);
	}
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}
void	freestack(t_node **stack)
{
	t_node *temp;
	t_node *actual;

	if (!stack)
		return ;
	actual = *stack;
	while (actual)
	{
		temp = actual->next;
		free(actual);
		actual = temp;
	}
	stack = NULL;
}

t_node	*find_last(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}