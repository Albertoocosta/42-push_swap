/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nodes2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:00:43 by cda-fons          #+#    #+#             */
/*   Updated: 2024/10/20 19:33:32 by cda-fons         ###   ########.fr       */
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
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
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
