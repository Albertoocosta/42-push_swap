/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:00:43 by cda-fons          #+#    #+#             */
/*   Updated: 2024/10/19 12:43:17 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_node	*add_node_to_list(t_node **stack, int content)
{
	t_node	*new_node;
	t_node	*last_node;
	
	if (!stack)
		return (NULL);
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->nbr = content;
	new_node->cheap = 0;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
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
		actual->nbr = 0;
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