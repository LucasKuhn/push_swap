/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex-ku <lalex-ku@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:05:43 by lalex-ku          #+#    #+#             */
/*   Updated: 2022/04/07 00:12:28 by lalex-ku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;
	t_stack	*aux;

	node = *stack_b;
	while (node)
	{	
		aux = node;
		node = node->next;
		free(aux);
	}
	node = *stack_a;
	while (node)
	{	
		aux = node;
		node = node->next;
		free(aux);
	}
}

int	stack_len(t_stack **stack_a)
{
	t_stack	*node;
	int		len;

	node = *stack_a;
	len = 0;
	while (node)
	{
		len++;
		node = node->next;
	}
	return (len);
}

void	stack_append(t_stack **stack, int number)
{
	struct s_stack	*new_node;
	struct s_stack	*aux_node;

	new_node = malloc(sizeof(struct s_stack));
	new_node->data = number;
	new_node->next = NULL;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	aux_node = *stack;
	while (aux_node->next)
		aux_node = aux_node->next;
	aux_node->next = new_node;
}

int	is_sorted(t_stack **stack)
{
	t_stack	*node;

	node = *stack;
	while (node)
	{
		if (!node->next)
			return (1);
		if (node->next->data < node->data)
			return (0);
		node = node->next;
	}
	return (0);
}

int	find_smallest_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;
	int		lowest_value;
	int		i;

	if (*stack_b)
		lowest_value = (*stack_b)->data + 1;
	else
		lowest_value = 1;
	node = *stack_a;
	i = 0;
	while (node)
	{
		if (node->data == lowest_value)
			return (i);
		i++;
		node = node->next;
	}
	return (0);
}
