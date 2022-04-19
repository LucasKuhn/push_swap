/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex-ku <lalex-ku@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:12:48 by lalex-ku          #+#    #+#             */
/*   Updated: 2022/04/19 13:30:40 by lalex-ku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	push_swap(int argc, const char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (EXIT_SUCCESS);
	check_args(argc, argv);
	initialize(argc, argv, &stack_a, &stack_b);
	if (stack_len(&stack_a) <= 3)
		tiny_sort(&stack_a, &stack_b);
	else if (stack_len(&stack_a) <= 50)
		bubble_sort(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b);
	free_stacks(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}
