/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:00:43 by cda-fons          #+#    #+#             */
/*   Updated: 2024/11/04 16:57:02 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

long	ft_atol(char *nbr)
{
	long	n;
	int		i;
	int		sig;

	n = 0;
	sig = 1;
	i = 0;
	while (nbr[i] && nbr[i] == ' ')
		i++;
	if (!nbr[i])
		return (1);
	if (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sig *= -1;
		i++;
	}
	while (nbr[i] && ft_isdigit(nbr[i]))
	{
		n = n * 10 + nbr[i] - '0';
		i++;
	}
	return (n * sig);
}

void	ft_error(t_node **stack_a, char **argv)
{
	if (stack_a)
		freestack(stack_a);
	if (argv)
		free_argv(argv);
	ft_printf("Error\n");
	exit(1);
}

bool	issorted(t_node *node)
{
	if (!node)
		return (1);
	while (node->next)
	{
		if (node->nbr > node->next->nbr)
			return (false);
		node = node->next;
	}
	return (true);
}

int	is_repeat(t_node *stack_a, int nbr)
{
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if (stack_a->nbr == nbr)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}
