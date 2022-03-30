/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex-ku <lalex-ku@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:05:24 by lalex-ku          #+#    #+#             */
/*   Updated: 2022/03/29 17:52:22 by lalex-ku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h" // libft
# include <unistd.h> // write
# include <stdlib.h> // exit

# define MAX_INT 2147483647

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

void	check_args(int argc, char const *argv[]);
int		push_swap(int argc, char const *argv[]);
int		stack_len(t_stack **stack_a);
void	stack_append(t_stack **stack, int number);
void	initialize(int argc, const char **argv, t_stack **a, t_stack **b);
int		is_sorted(t_stack **stack);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rra(t_stack **stack_a);
void	sa(t_stack **stack_a);
int		find_smallest_position(t_stack **stack_a, t_stack **stack_b);

#endif
