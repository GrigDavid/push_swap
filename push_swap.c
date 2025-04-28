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
#include <limits.h>

void	print_arr(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
		ft_printf("%d ", arr[i++]);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	num;

	sign = 0;
	num = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			num = 10 * num + *str - '0';
		else
			return (0);
		if (num + sign > INT_MAX)
			return (0);
		str++;
	}
	if (sign)
		num *= sign;
	return (num);
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

int	main(int argc, char **argv)
{
	int		*arr;
	int		*swp;
	t_list	*a;
	t_list	*b;

	b = NULL;
	if (argc < 2)
		return (0);
	arr = parser(argc, argv);
	if (!arr)
		return (0);
	swp = arr_cpy(arr, argc - 1);
	if (!swp)
		return (free(arr), 0);
	sort(swp, argc - 1);
	normalise(arr, swp, argc - 1);
	free(swp);
	a = lst_ise(arr, argc - 1);
	fill_b(&a, &b);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
