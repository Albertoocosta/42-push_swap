/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:32:32 by cda-fons          #+#    #+#             */
/*   Updated: 2024/10/25 19:52:55 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	stackinit(t_node **stack_a, char **argv)
{
	int		i;
	long	nbr;

	i = 0;
	if (!ft_strncmp(argv[0], "./push", 6))
		i++;
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

void	free_argv(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		free (argv[i]);
	}
	free(argv);
}

void	ft_aux(char **aux, char ***argv)
{
	*aux = argv[0][1];
	*argv = ft_split(*aux, 32);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	*aux;

	a = NULL;
	b = NULL;
	aux = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		ft_aux(&aux, &argv);
	stackinit(&a, argv);
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
	if (aux)
		free_argv(argv);
}
