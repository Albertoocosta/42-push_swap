/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:32:32 by cda-fons          #+#    #+#             */
/*   Updated: 2024/10/01 17:25:34 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	stackinit(t_node **stack_a, char ***split, char **argv)
{
	int 	i;
	long	nbr;
	t_node	*last_node;

	last_node = NULL;
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
			last_node = *stack_a;
		}
		else
			last_node = add_node_to_list(last_node, (int)nbr);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_node		*node;
	char 		**split;
	int 		i;

	if (argc < 2 || (argc == 2 && !argv[1][0]))
	{
		ft_printf("Error\n");
		return (1);
	}
	else if (argc == 2)
	{
		while (argv[1][i])
		{
			if (!(argv[1][i] >= '0' && argv[1][i] <= '9') || !(argv[1][i] == ' '))
			{
				ft_printf("Erroraqui\n");
				return (1);
			}
			i++;	
		}
		split = ft_split(argv[1], ' ');		
	}
	stackinit(&node, &split, argv);
}
