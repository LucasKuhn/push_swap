/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex-ku <lalex-ku@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:12:48 by lalex-ku          #+#    #+#             */
/*   Updated: 2022/03/29 10:34:02 by lalex-ku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include <stdio.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

#define MAX_INT 2147483647

void	stack_append(t_stack **stack, int number)
{
	struct s_stack	*new_node;
	struct s_stack	*aux_node;

	new_node = malloc(sizeof(struct s_stack));
	new_node->data = number;
	new_node->next = NULL;
	if (!*stack)
	{
		new_node->prev = NULL;
		*stack = new_node;
		return ;
	}
	aux_node = *stack;
	while (aux_node->next)
		aux_node = aux_node->next;
	aux_node->next = new_node;
	new_node->prev = aux_node;
}

void	populate(t_stack **stack, int *arr)
{
	while (*arr)
	{
		stack_append(stack, *arr);
		arr++;
	}
}

void	print_stack(t_stack *stack)
{
	printf("Printing\n");
	while (stack)
	{
		printf("->(%i)\n", stack->data);
		stack = stack->next;
	}
	return ;
}

void	normalize(int **arr_p, int argc, const char *argv[])
{
	int	lowest;
	int	lowest_pos;
	int	*arr;

	int x, i;
	arr = *arr_p;
	arr = malloc(sizeof(int) * argc + 1);
	i = 0;
	while (i++ < argc)
		ft_memset(&arr[i], 0, sizeof(int));
	x = 1;
	while (x < argc)
	{
		i = 1;
		lowest = 2147483647;
		while (i < argc)
		{
			if (!arr[i - 1] && atoi(argv[i]) < lowest)
			{
				lowest_pos = i;
				lowest = atoi(argv[i]);
			}
			i++;
		}
		arr[lowest_pos - 1] = x;
		x++;
	}
	*arr_p = arr;
}

void	initialize(t_stack **stack)
{
	*stack = NULL;
	return ;
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	printf("pb\n");
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

void	ra(t_stack **stack_a)
{
	t_stack	*second;
	t_stack	*last;

	if (!*stack_a)
		return ;
	printf("ra\n");
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
	printf("rra\n");
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

	printf("sa\n");
	first = *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
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
	if (stack_len(stack) > 5)
		return (0);
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
void	pa(t_stack **stack_b)
{
	if (!*stack_b)
		return ;
	printf("pa\n");
	*stack_b = (*stack_b)->next;
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

void init(int argc, const char **argv, t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = NULL;
	*stack_b = NULL;
	
	int		*arr;

	normalize(&arr, argc, argv);
	populate(stack_a, arr);
}

int	push_swap(int argc, const char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	check_args(argc, argv);
	init(argc, argv, &stack_a, &stack_b);
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
