/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex-ku <lalex-ku@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:21:56 by lalex-ku          #+#    #+#             */
/*   Updated: 2022/04/19 13:30:49 by lalex-ku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	should_swap(t_stack **stack)
{
	return ((*stack)->next && (*stack)->next->data < (*stack)->data);
}

static int	should_go_down(t_stack **stack_a, t_stack **stack_b)
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

void	tiny_sort(t_stack **stack_a, t_stack **stack_b)
{
	while (!is_sorted(stack_a))
	{
		if (should_swap(stack_a))
		{
			sa(stack_a);
			continue ;
		}
		if (should_go_down(stack_a, stack_b))
			ra(stack_a);
		else
			rra(stack_a);
	}
}
