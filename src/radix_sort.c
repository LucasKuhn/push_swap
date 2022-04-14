/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex-ku <lalex-ku@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:21:49 by lalex-ku          #+#    #+#             */
/*   Updated: 2022/04/14 00:45:02 by lalex-ku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// https://stackoverflow.com/questions/160930/how-do-i-check-if-an-integer-is-even-or-odd
// if (is_odd(node->data >> power))
static int	is_odd(int i)
{
	return ((i % 2));
}



// https://stackoverflow.com/questions/66674378/2-to-the-power-of-n-in-c-without-pow
// bitshift way: return(1 << exp);
static int	power_of_two(int exp)
{
	if (exp == 0)
		return (1);
	if (exp > 0)
		return (2 * power_of_two(exp - 1));
	else
		return (1);
}



void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;
	t_stack	*start;
	int		power;
	int		first_pass;

	power = 0;
	while (!is_sorted(stack_a))
	{
		node = *stack_a;
		start = NULL;
		first_pass = 0;
		while (node && node != start)
		{
			if (is_odd(node->data / power_of_two(power)))
			{
				if (first_pass++ == 0)
					start = *stack_a;
				ra(stack_a);
			}
			else
				pb(stack_a, stack_b);
			node = *stack_a;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		power++;
	}
}
