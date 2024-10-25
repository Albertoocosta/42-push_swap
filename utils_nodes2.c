/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nodes2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:00:43 by cda-fons          #+#    #+#             */
/*   Updated: 2024/10/25 19:41:42 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_node	*max(t_node *stack)
{
	long	maxi;
	t_node	*max_node;

	if (!stack)
		return (NULL);
	maxi = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > maxi)
		{
			maxi = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_node	*min(t_node *stack)
{
	long	mini;
	t_node	*min_node;

	if (!stack)
		return (NULL);
	mini = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < mini)
		{
			mini = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

int	check_syntax(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])) && !(str[i] != '-' || str[i] != '+'))
			return (1);
		i++;
	}
	return (0);
}

void	actual_index(t_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stacklen(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->abovemedian = true;
		else
			stack->abovemedian = false;
		stack = stack->next;
		i++;
	}
}

t_node	*get_cheap(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheap)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
