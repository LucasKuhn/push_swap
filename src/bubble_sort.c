/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex-ku <lalex-ku@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:21:53 by lalex-ku          #+#    #+#             */
/*   Updated: 2022/04/14 00:21:54 by lalex-ku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	should_push(t_stack **stack_a, t_stack **stack_b)
{
	int	lowest_value;

	if (*stack_b)
		lowest_value = (*stack_b)->data + 1;
	else
		lowest_value = 1;
	return ((*stack_a)->data == lowest_value);
}

int	should_go_down(t_stack **stack_a, t_stack **stack_b)
{
	int	middle_point;
	int	smallest_position;

	if (!*stack_a)
		return (0);
	middle_point = stack_len(stack_a) / 2;
	smallest_position = find_smallest_position(stack_a, stack_b);
	if (smallest_position <= middle_point)
		return (1);
	else
		return (0);
}

void	bubble_sort(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_a && !is_sorted(stack_a))
	{
		if (should_push(stack_a, stack_b))
			pb(stack_a, stack_b);
		if (should_go_down(stack_a, stack_b))
			ra(stack_a);
		else
			rra(stack_a);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}