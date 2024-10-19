/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:32:32 by cda-fons          #+#    #+#             */
/*   Updated: 2024/10/19 12:43:30 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	stackinit(t_node **stack_a, char **argv)
{
	int 	i;
	long	nbr;
	
	i = -1;
	while (argv[++i])
	{
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_error(stack_a, NULL, argv);
		if (is_repeat(*stack_a, (int)nbr))
			ft_error(stack_a, NULL, argv);
		if (stack_a == NULL)
		{
			*stack_a = create_node((int)nbr);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_node	*a;
//	t_node	*b;
	
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stackinit(&a, argv);
	if (!issorted(a))
	{
		if (stacklen(a) == 2)
			sa(&a, false);
		else if (stacklen(a) == 3)
			sort_three(&a);
//		else
			//sortstacks(&a, &b);
	}
	freestack(&a);
	return (0);
}
