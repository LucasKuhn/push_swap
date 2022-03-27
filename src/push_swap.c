/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex-ku <lalex-ku@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:12:48 by lalex-ku          #+#    #+#             */
/*   Updated: 2022/03/25 16:35:22 by lalex-ku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include <stdio.h>

typedef struct s_stack {
	int data;
	struct s_stack* next;
	struct s_stack* prev;
}	t_stack;

void stack_append(t_stack **stack, int number)
{
	struct s_stack *new_node;
	struct s_stack *aux_node;
	

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

void populate(t_stack **stack, int *arr)
{
	while( *arr )
	{
		stack_append(stack, *arr);
		arr++;
	}
}

void print_stack(t_stack *stack)
{
	printf("Printing\n");
	while (stack)
	{
		printf("->(%i)\n", stack->data);
		stack = stack->next;
	}
	return ;
}

void normalize(int **arr_p, int argc, const char *argv[])
{
	int x, i;
	int lowest;
	int lowest_pos;

	int *arr;
	arr = *arr_p;
	
	arr = malloc(sizeof(int) * argc + 1);
	i = 0;
	while(i++<argc)
		ft_memset(&arr[i], 0, sizeof(int));
	x = 1;
	while(x < argc)
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

void initialize(t_stack **stack)
{
	*stack = NULL;
	return ;
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
	printf("pb\n");

	t_stack *node;

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

void ra(t_stack **stack_a)
{
	printf("ra\n");
	t_stack *second;
	t_stack *last;

	if (!*stack_a)
		return;
	second = (*stack_a)->next;
	last = *stack_a;
	while (last && last->next)
		last = last->next;
	last->next = *stack_a;
	(*stack_a)->next = NULL;
	*stack_a = second;
}

void sa(t_stack **stack_a)
{
	printf("sa\n");
	t_stack *first;
	t_stack *second;

	first = *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
}

int push_swap(int argc, const char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*arr;
	
	check_args(argc, argv);
	initialize(&stack_a);
	normalize(&arr, argc, argv);
	populate(&stack_a, arr);
	
	t_stack	*node;
	int max;
	max = 1;
	node = stack_a;
	while (stack_a)
	{
		node = stack_a;
		if (node->data < argc - 1)
		{
			if (node->next && node->next->data < node->data)
			{
				sa(&stack_a);
				node = stack_a;
			}
		}
		if (node->next && node->next->data == max)
		{
			ra(&stack_a);
			node = stack_a;
		}
		if (node->data == max)
		{
			pb(&stack_a, &stack_b);
			max++;
			node = stack_a;
		}
		else 
			ra(&stack_a);
	}
	
	// printf("stack_b:\n");
	// print_stack(stack_b);

	// printf("stack_a:\n");
	// print_stack(stack_a);

	int i = 0;
	while (i++<argc)
		printf("pa\n");

	return (EXIT_SUCCESS);
}
