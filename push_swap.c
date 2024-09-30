/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:32:32 by cda-fons          #+#    #+#             */
/*   Updated: 2024/09/29 19:15:47 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	stackinit()
{

}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	char 		**split;
	int 		i;

	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] < '0' && argv[1][i] > '9')
				return (1);
		}
	}	
}