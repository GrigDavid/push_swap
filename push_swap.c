/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:05:49 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/03/17 16:05:51 by dgrigor2         ###   ########.fr       */
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

void	r(int *arr, int start, int len)
{
	int	swap;
	int	i;

	i = start + 1;
	swap = arr[start];
	while (i < len)
	{
		arr[i - 1] = arr[i];
		i++;
	}
	arr[i - 1] = swap;
}

void	rr(int *arr, int start, int len)
{
	int	swap;
	int	i;

	i = len - 2;
	swap = arr[len - 1];
	while (i >= start)
	{
		arr[i + 1] = arr[i];
		i--;
	}
	arr[start] = swap;
}

int	*parser(int argc, char **argv)
{
	int	i;
	int	*res;
	int	j;

	i = 1;
	res = (int *)malloc(sizeof(int) * (argc - 1));
	if (!res)
		return (NULL);
	while (i < argc)
	{
		res[i - 1] = ft_atoi(argv[i]);
		j = 0;
		while (j < i - 1)
		{
			if (res[j++] == res[i - 1])
				return (free(res), NULL);
		}
		if (res[i - 1] == 0 && !(argv[i][0] == '0' && !argv[i][1]))
			return (free(res), NULL);
		i++;
	}
	reverse(res, argc - 1);
	return (res);
}

void	push_swap(int *arr, int len)
{
	int	lena;
	int	lenb;
	int	i;
	int	j;
	int	max;

	lena = len;
	lenb = 0;
	while (lena > 0)
	{
		i = 0;
		max = 0;
		while (i <= (lena / 2) + (lena % 2))
		{
			if (arr[i] > arr[max])
			{
				max = i;
			}
			if (arr[lena - 1 - i] > arr[max])
			{
				max = lena - 1 - i;
			}
			i++;
		}
		if (max >= lena / 2)
		{
			while (max < lena - 1)
			{
				rr(arr, 0, lena);
				ft_printf("rra\n");
				max++;
			}
		}
		else
		{
			while (max >= 0)
			{
				r(arr, 0, lena);
				ft_printf("ra\n");
				max--;
			}
		}
		ft_printf("pb\n");
		lena--;
		lenb++;
	}
	while (lenb > 0)
	{
		ft_printf("rrb\npa\n");
		lenb--;
		lena++;
	}
	// print_arr(arr, len);
	// ft_printf("%d\n", lenb);
}





/*
void	push_swap(int *arr, int len)
{
	//print_arr(arr, len);
	int	i;
	int	max;
	int	j;
	
	j = len;
	while (len > 0)
	{

		i = 0;
		max = 0;
		while (i <= (len / 2) + (len % 2))
		{
			if (arr[i] > arr[max])
			{
				max = i;
			}
			if (arr[len - 1 - i] > arr[max])
			{
				max = len - 1 - i;
			}
			i++;
		}
		if (max >= len / 2)
		{
			while (max < len - 1)
			{
				rra(arr, len);
				ft_printf("ra\n");
				max++;
				//print_arr(arr, len);
			}
		}
		else
		{
			while (max >= 0)
			{
				ra(arr, len);
				ft_printf("rra\n");
				max--;
				//print_arr(arr, len);
			}
		}
		//print_arr(arr, len);
		ft_printf("pb\n");
		len--;
	}
	while (j > 0)
	{
		ft_printf("rrb\npa\n");
		len++;
		j--;
	}
	//while ()
}*/

int	main(int argc, char **argv)
{
	int	*arr;

	if (argc < 2)
		return (0);
	arr = parser(argc, argv);
	if (!arr)
		return (0);
	push_swap(arr, argc - 1);
	// print_arr(arr, argc - 1);
	// ra(arr, argc - 1);
	// print_arr(arr, argc - 1);
	free(arr);
	return (0);
}
