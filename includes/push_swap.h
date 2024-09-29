/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cda-fons <cda-fons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:14:58 by cda-fons          #+#    #+#             */
/*   Updated: 2024/09/29 12:32:23 by cda-fons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include "../Libft/libft.a"
# include "../Printf/libftprintf.a"

typedef struct s_stack
{
	int		nbr;
	int		index;
	struct s_stack	*next;
	struct s_stack	*target;
}				t_stack;


#endif