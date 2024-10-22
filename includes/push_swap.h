/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:14:58 by cda-fons          #+#    #+#             */
/*   Updated: 2024/10/20 19:38:08 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <limits.h>
# include "../Libft/libft.h"
# include "../Printf/ft_printf.h"

typedef struct s_node
{
	long			nbr;
	int				index;
	int				cost;
	bool			cheap;
	bool			abovemedian;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
}				t_node;

void	stackinit(t_node **stack_a, char **argv);
t_node	*add_node_to_list(t_node **stack, int content);
long	ft_atol(char *nbr);
int		stacklen(t_node *node);
bool	issorted(t_node *node);
int		is_repeat(t_node *stack_a, int nbr);
void	ft_error(t_node **stack_a);
void	freestack(t_node **stack);
t_node	*find_last(t_node *stack);
void	push(t_node **dest, t_node **origin);
void	pa(t_node **a, t_node **b, bool print);
void	pb(t_node **a, t_node **b, bool print);
void	rotate(t_node **stack);
void	ra(t_node **a, bool print);
void	rb(t_node **b, bool print);
void	rr(t_node **a, t_node **b, bool print);
void	rotate_both(t_node **a, t_node **b, t_node *node_cheap);
void	rev_rotate(t_node **stack);
void	rra(t_node **a, bool print);
void	rrb(t_node **b, bool print);
void	rrr(t_node **a, t_node **b, bool print);
void	rev_rotate_both(t_node **a, t_node **b, t_node *node_cheap);
void	swap(t_node **head);
void	sa(t_node **a, bool print);
void	sb(t_node **b, bool print);
void	ss(t_node **a, t_node **b, bool print);
void	sort_three(t_node **stack);
void	sortstacks(t_node **a, t_node **b);
t_node	*max(t_node *stack);
t_node	*min(t_node *stack);
int		check_syntax(char *str);
void	actual_index(t_node *stack);
void	set_cheapest(t_node *stack);
t_node	*get_cheap(t_node *stack);
void	cost(t_node *a, t_node *b);
void	init_node_a(t_node *a, t_node *b);
void	a_to_b(t_node **a, t_node **b);
void	set_target_to_a(t_node *a, t_node *b);
void	prepare_to_push(t_node **stack,
			t_node *node_on_top, char name_of_stack);
void	init_node_b(t_node *a, t_node *b);
void	b_to_a(t_node **a, t_node **b);
void	set_target_to_b(t_node *a, t_node *b);
void	min_to_top(t_node **a);

#endif