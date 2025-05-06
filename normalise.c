/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:16:07 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/05/06 14:24:02 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arr_cpy(int *arr, int len)
{
	int	*res;
	int	i;

	if (len == 0)
		return (0);
	res = (int *)malloc(sizeof(int) * len);
	if (!res)
		return (0);
	i = 0;
	while (i < len)
	{
		res[i] = arr[i];
		i++;
	}
	sort(res, len);
	normalise(arr, res, len);
	free(res);
	return (1);
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

void	swap(int *arr, int a, int b)
{
	int	tmp;

	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
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

t_stack	*lst_ise(int *arr, int len)
{
	t_stack	*lst;
	int		i;
	t_stack	*tmp;

	i = 0;
	lst = 0;
	while (i < len)
	{
		tmp = ft_stknew(arr[i++]);
		if (!tmp)
		{
			ft_stkclear(&lst);
			free(arr);
			return (NULL);
		}
		if (!lst)
			lst = tmp;
		else
			ft_stkadd_back(&lst, tmp);
	}
	free(arr);
	return (lst);
}
