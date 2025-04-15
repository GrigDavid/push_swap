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

void	print_arr(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
		ft_printf("%d ", arr[i++]);
}

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
	int		*b;
	t_list	*lst;
	t_list	*swp;

	swp = NULL;

	if (argc < 2)
		return (0);
	arr = parser(argc, argv);
	if (!arr)
		return (0);
	b = arr_cpy(arr, argc - 1);
	if (!b)
		return (free(arr), 0);
	sort(b, argc - 1);
	normalise(arr, b, argc - 1);
	free(b);
	lst = lst_ise(arr, argc - 1);
	// ra(&lst);
	// ft_lstiter(lst, ft_putnbr);
	algo(&lst, &swp);
	// ft_lstiter(lst, ft_putnbr);
	// ft_printf("\n");
	// ft_lstiter(swp, ft_putnbr);
	return (0);
}
