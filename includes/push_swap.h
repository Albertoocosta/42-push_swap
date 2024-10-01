/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:14:58 by cda-fons          #+#    #+#             */
/*   Updated: 2024/10/01 17:36:28 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <limits.h>
# include "../Libft/libft.a"
# include "../Printf/libftprintf.a"

typedef struct s_node
{
	int		nbr;
	int		index;
	int		cost;
	bool	cheap;
	bool	abovemedian;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
}				t_node;


int	stackinit(t_node **node, char ***split, char **argv, int argc);
t_node	*create_node(int content);
t_node	*add_node_to_list(t_node *node, int content);

#endif