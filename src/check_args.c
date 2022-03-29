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

	if (ft_strlen(str) > 10)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && str[i + 1])
			i++;
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	number = ft_atol(str);
	if (number > 2147483647 || number < -2147483648)
		return (0);
	return (1);
}

int	arr_includes(int *arr, int num)
{
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
	int *arr;
	int i;
	int num;

	i = 1;
	while (i < argc)
	{
		if (!str_is_int(argv[i]))
			exit_error();
		i++;
	}
	arr = malloc(sizeof(int) * (argc + 1));
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