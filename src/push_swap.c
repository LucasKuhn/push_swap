/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex-ku <lalex-ku@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:12:48 by lalex-ku          #+#    #+#             */
/*   Updated: 2022/03/30 17:00:06 by lalex-ku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int		should_swap(t_stack **stack);
int		should_push(t_stack **stack_a, t_stack **stack_b);
int		should_go_down(t_stack **stack_a, t_stack **stack_b);
void	solve_small(t_stack **stack_a, t_stack **stack_b);

int	push_swap(int argc, const char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	check_args(argc, argv);
	initialize(argc, argv, &stack_a, &stack_b);
	if (stack_len(&stack_a) <= 3)
		solve_small(&stack_a, &stack_b);
	while (stack_a && !is_sorted(&stack_a))
	{
		if (should_push(&stack_a, &stack_b))
			pb(&stack_a, &stack_b);
		if (should_go_down(&stack_a, &stack_b))
			ra(&stack_a);
		else
			rra(&stack_a);
	}
	while (stack_b)
		pa(&stack_b);
	return (EXIT_SUCCESS);
}

void	solve_small(t_stack **stack_a, t_stack **stack_b)
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

int	should_swap(t_stack **stack)
{
	return ((*stack)->next && (*stack)->next->data < (*stack)->data);
}

int	should_push(t_stack **stack_a, t_stack **stack_b)
{
	int	lowest_value;

	if (*stack_b)
		lowest_value = (*stack_b)->data + 1;
	else
		lowest_value = 1;
	return ((*stack_a)->data == lowest_value);
}
