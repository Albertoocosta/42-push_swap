/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortstacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:00:43 by cda-fons          #+#    #+#             */
/*   Updated: 2024/10/19 12:43:17 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	both_rotate(t_node **a, t_node **b, t_node *cheap)
{
	while (*b != cheap->target && *a != cheap)
		rr(a, b, false);
	actual_index(*a);
	actual_index(*b);
}

void	both_rev_rotate(t_node **a, t_node **b, t_node *cheap)
{
	while (*b != cheap->target && *a != cheap)
		rrr(a, b, false);
	actual_index(*a);
	actual_index(*b);
}

void	sortstacks(t_node **a, t_node **b)
{
	int	a_len;

	a_len = stacklen(*a);
	if (a_len-- > 3 && !issorted(*a))
		pb(b, a, false);
	if (a_len-- > 3 && !issorted(*a))
		pb(b, a, false);
	while (a_len-- > 3 && !issorted(*a))
	{
		init_nodes_a(*a, *b);
		a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		b_to_a(a, b);
	}
	actual_index(*a);
	min_to_top(a);
}
