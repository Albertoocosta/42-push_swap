/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:31:35 by cda-fons          #+#    #+#             */
/*   Updated: 2024/10/20 19:35:27 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	prepare_to_push(t_node **stack, t_node *node_on_top, char name_of_stack)
{
	while (*stack != node_on_top)
	{
		if (name_of_stack == 'a')
		{
			if (node_on_top->abovemedian)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (name_of_stack == 'b')
		{
			if (node_on_top->abovemedian)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

void	b_to_a(t_node **a, t_node **b)
{
	prepare_to_push(a, (*b)->target, 'a');
	pa(a, b, false);
}

void	min_to_top(t_node **a)
{
	while ((*a)->nbr != min(*a)->nbr)
	{
		if (min(*a)->abovemedian)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	set_target_to_b(t_node *a, t_node *b)
{
	t_node	*actual_a;
	t_node	*node_target;
	long	best_index;

	while (b)
	{
		best_index = LONG_MAX;
		actual_a = a;
		while (actual_a)
		{
			if (actual_a->nbr > b->nbr && actual_a->nbr < best_index)
			{
				best_index = actual_a->nbr;
				node_target = actual_a;
			}
			actual_a = actual_a->next;
		}
		if (best_index == LONG_MAX)
			b->target = min(a);
		else
			b->target = node_target;
		b = b->next;
	}
}

void	init_node_b(t_node *a, t_node *b)
{
	actual_index(a);
	actual_index(b);
	set_target_to_b(a, b);
}
