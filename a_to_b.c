/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:51:34 by cda-fons          #+#    #+#             */
/*   Updated: 2024/10/20 19:35:12 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	set_target_to_a(t_node *a, t_node *b)
{
	t_node	*actual_b;
	t_node	*node_target;
	long	best_index;

	while (a)
	{
		best_index = LONG_MIN;
		actual_b = b;
		while (actual_b)
		{
			if (actual_b->nbr < a->nbr && actual_b->nbr > best_index)
			{
				best_index = actual_b->nbr;
				node_target = actual_b;
			}
			actual_b = actual_b->next;
		}
		if (best_index == LONG_MIN)
			a->target = max(b);
		else
			a->target = node_target;
		a = a->next;
	}
}

void	set_cheapest(t_node *stack)
{
	long	cheap_value;
	t_node	*node_cheap;

	if (!stack)
		return ;
	cheap_value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheap_value)
		{
			cheap_value = stack->cost;
			node_cheap = stack;
		}
		stack = stack->next;
	}
	node_cheap->cheap = true;
}

void	cost(t_node *a, t_node *b)
{
	int	a_len;
	int	b_len;

	a_len = stacklen(a);
	b_len = stacklen(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->abovemedian))
			a->cost = a_len - (a->index);
		if (a->target->abovemedian)
			a->cost += a->target->index;
		else
			a->cost += b_len -(a->target->index);
		a = a->next;
	}
}

void	a_to_b(t_node **a, t_node **b)
{
	t_node	*cheap_node;

	cheap_node = get_cheap(*a);
	if (cheap_node->abovemedian && cheap_node->target->abovemedian)
		rotate_both(a, b, cheap_node);
	else if (!(cheap_node->abovemedian) && !(cheap_node->target->abovemedian))
		rev_rotate_both(a, b, cheap_node);
	prepare_to_push(a, cheap_node, 'a');
	prepare_to_push(b, cheap_node->target, 'b');
	pb(b, a, false);
}

void	init_node_a(t_node *a, t_node *b)
{
	actual_index(a);
	actual_index(b);
	set_target_to_a(a, b);
	cost(a, b);
	set_cheapest(a);
}
