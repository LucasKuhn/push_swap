/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex-ku <lalex-ku@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:21:49 by lalex-ku          #+#    #+#             */
/*   Updated: 2022/04/19 13:40:12 by lalex-ku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// https://stackoverflow.com/a/160935
static int	is_odd(int i)
{
	return ((i % 2));
}

static int	is_even(int i)
{
	return (!is_odd(i));
}

// Using bitshift: return(1 << exp);
// https://stackoverflow.com/a/66674666
static int	power_of_two(int exp)
{
	if (exp > 0)
		return (2 * power_of_two(exp - 1));
	else
		return (1);
}

// Using bitshift: return (is_even(value >> power)); 
static int	should_push(int value, int power)
{
	return (is_even(value / power_of_two(power)));
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	power;
	int	i;
	int	len;

	len = stack_len(stack_a);
	power = 0;
	while (!is_sorted(stack_a))
	{
		i = 0;
		while (i < len)
		{
			if (should_push((*stack_a)->data, power))
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			i++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		power++;
	}
}
