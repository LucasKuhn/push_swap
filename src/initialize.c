/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex-ku <lalex-ku@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:43:24 by lalex-ku          #+#    #+#             */
/*   Updated: 2022/04/05 22:07:34 by lalex-ku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	populate(t_stack **stack, int *arr)
{
	while (*arr)
	{
		stack_append(stack, *arr);
		arr++;
	}
}

void	normalize(int **arr_p, int argc, const char *argv[])
{
	int	lowest;
	int	lowest_pos;
	int	x;
	int	i;

	*arr_p = ft_calloc(argc + 1, sizeof(int));
	x = 1;
	while (x < argc)
	{
		i = 1;
		lowest = MAX_INT;
		while (i < argc)
		{
			if (!(*arr_p)[i - 1] && atoi(argv[i]) < lowest)
			{
				lowest_pos = i;
				lowest = atoi(argv[i]);
			}
			i++;
		}
		(*arr_p)[lowest_pos - 1] = x;
		x++;
	}
}

void	initialize(int argc, const char **argv, t_stack **a, t_stack **b)
{
	int	*aux_arr;

	*a = NULL;
	*b = NULL;
	normalize(&aux_arr, argc, argv);
	populate(a, aux_arr);
	free(aux_arr);
}
