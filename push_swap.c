/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:24:14 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/04/09 13:24:15 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			num = 10 * num + *str - '0';
		else
			return (0);
		str++;
	}
	return (sign * num);
}

void	reverse(int *arr, int len)
{
	int	swap;
	int	i;

	i = 0;
	while (i < len / 2)
	{
		swap = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = swap;
		i++;
	}
}

int	*parser(int argc, char **argv)
{
	int	i;
	int	*res;
	int	j;

	i = 0;
	argc--;
	res = (int *)malloc(sizeof(int) * argc);
	if (!res)
		return (NULL);
	while (i < argc)
	{
		res[i] = ft_atoi(argv[i + 1]);
		j = 0;
		while (j < i)
		{
			if (res[j] == res[i])
				return (free(res), NULL);
			j++;
		}
		if (res[i] == 0 && !(argv[i + 1][0] == '0' && !argv[i + 1][1]))
			return (free(res), NULL);
		i++;
	}
	return (res);
}

void	print_arr(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("%d ", arr[i]);
		i++;
	}
	ft_printf("\n");
}


void	swap(int *arr, int a, int b)
{
	int	swap;

	swap = arr[a];
	arr[a] = arr[b];
	arr[b] = swap;
}

void	normalise(int *a, int *b, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (a[i] == b[j])
		{
			a[i] = j + 1;
			j = 0;
			i++;
		}
		else
			j++;
	}
}

int	*arr_cpy(int *arr, int len)
{
	int	*res;
	int	i;

	res = (int *)malloc(sizeof(int) * len);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = arr[i];
		i++;
	}
	return (res);
}

void	sort(int *arr, int len)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	j = 1;
	min = 0;
	while (i < len)
	{
		if (j == len)
		{
			swap(arr, i, min);
			i++;
			min = i;
			j = i;
		}
		else if (arr[j] < arr[min])
			min = j;
		j++;
	}
}

int	main(int argc, char **argv)
{
	int	*arr;
	int	*b;

	arr = parser(argc, argv);
	if (!arr)
		return (0);
	b = arr_cpy(arr, argc - 1);
	if (!b)
		return (free(arr), 0);
	sort(b, argc - 1);
	normalise(arr, b, argc - 1);
	print_arr(arr, argc - 1);
	free(arr);
	return (0);
}
