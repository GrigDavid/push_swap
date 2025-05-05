/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:24:14 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/05/05 16:53:56 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	is_sorted(t_stack *lst)
{
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		*arr;
	int		*swp;
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	arr = parser(&argc, argv);
	if (!arr)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	swp = arr_cpy(arr, argc);
	if (!swp)
	{
		free(arr);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	sort(swp, argc);
	normalise(arr, swp, argc);
	free(swp);
	a = lst_ise(arr, argc);
	if (!is_sorted(a))
		fill_b(&a, &b);
	ft_stkclear(&a);
	ft_stkclear(&b);
	return (0);
}
