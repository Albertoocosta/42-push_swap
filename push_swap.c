/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:32:32 by cda-fons          #+#    #+#             */
/*   Updated: 2024/10/20 19:30:07 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	stackinit(t_node **stack_a, char **argv)
{
	int		i;
	long	nbr;

	i = 1;
	while (argv[i])
	{
		if (check_syntax(argv[i]))
			ft_error(stack_a);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_error(stack_a);
		if (is_repeat(*stack_a, (int)nbr))
			ft_error(stack_a);
		add_node_to_list(stack_a, (int)nbr);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stackinit(&a, argv + 1);
	if (!issorted(a))
	{
		if (stacklen(a) == 2)
			sa(&a, false);
		else if (stacklen(a) == 3)
			sort_three(&a);
		else
			sortstacks(&a, &b);
	}
	freestack(&a);
	return (0);
}
