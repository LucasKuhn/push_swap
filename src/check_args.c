/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalex-ku <lalex-ku@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:43:07 by lalex-ku          #+#    #+#             */
/*   Updated: 2022/04/19 16:16:25 by lalex-ku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	exit_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	str_is_int(const char *str)
{
	long	number;
	int		i;

	if (ft_strlen(str) > 11)
		return (0);
	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '-' && str[i + 1])
			i++;
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	number = ft_atol(str);
	if (number > MAX_INT || number < MIN_INT)
		return (0);
	return (1);
}

int	arr_includes(int *arr, int num)
{
	static int	has_zero;

	if (num == 0 && has_zero++ != 0)
		return (1);
	while (*arr)
	{
		if (*arr == num)
			return (1);
		arr++;
	}
	return (0);
}

void	check_args(int argc, char const *argv[])
{
	int	*arr;
	int	i;
	int	num;

	i = 1;
	while (i < argc)
	{
		if (!str_is_int(argv[i]))
			exit_error();
		i++;
	}
	arr = ft_calloc((argc + 1), sizeof(int));
	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (arr_includes(arr, num))
		{
			free(arr);
			exit_error();
		}
		arr[i - 1] = num;
		i++;
	}
	free(arr);
}
