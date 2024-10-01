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

int	stackinit(t_node **node, char ***split, char **argv, int argc)
{
	int i;
	
	if (argc == 2)
	{
		**split = ft_split(argv[1], ' ');
		
		
	}
}

int	main(int argc, char **argv)
{
	t_node		*node;
	char 		**split;
	int 		i;

	if (argc < 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	else if (argc == 2)
	{
		if (!argv[1][0])
		{
			ft_printf("Error\n");
			return (1);
		}
		while (argv[1][i])
		{
			if (argv[1][i] < '0' && argv[1][i] > '9')
				return (1);
			i++;
		}
	}
	stackinit(&node, &**split, **argv, argc);
}
