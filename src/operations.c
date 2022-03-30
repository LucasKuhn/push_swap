/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex-ku <lalex-ku@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:54:23 by lalex-ku          #+#    #+#             */
/*   Updated: 2022/03/29 10:55:27 by lalex-ku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	write(1, "pb\n", 3);
	node = *stack_a;
	*stack_a = node->next;
	if (!*stack_b)
	{
		node->next = NULL;
		*stack_b = node;
		return ;
	}
	node->next = *stack_b;
	*stack_b = node;
}

void	pa(t_stack **stack_b)
{
	if (!*stack_b)
		return ;
	write(1, "pa\n", 3);
	*stack_b = (*stack_b)->next;
}

void	ra(t_stack **stack_a)
{
	t_stack	*second;
	t_stack	*last;

	if (!*stack_a)
		return ;
	write(1, "ra\n", 3);
	second = (*stack_a)->next;
	last = *stack_a;
	while (last && last->next)
		last = last->next;
	last->next = *stack_a;
	(*stack_a)->next = NULL;
	*stack_a = second;
}

void	rra(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*next_to_last;

	if (!*stack_a)
		return ;
	write(1, "rra\n", 4);
	first = *stack_a;
	last = *stack_a;
	while (last->next)
	{
		if (last->next && !last->next->next)
			next_to_last = last;
		last = last->next;
	}
	last->next = first;
	next_to_last->next = NULL;
	*stack_a = last;
}

void	sa(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;

	write(1, "sa\n", 3);
	first = *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
}
