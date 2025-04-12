/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:55:50 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/04/12 16:55:51 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_list	**lstize(int *arr, int len)
{
	t_list	**lst;
	int		i;
	t_list	*tmp;

	i = 0;
	while (i < len)
	{
		tmp = ft_lstnew(arr[i++]);
		if (!tmp)
		{
			ft_lstclear(lst);
			return (NULL);
		}
		ft_lstadd_back(lst, tmp);
		free(tmp);
	}
	free(arr);
	return (lst);
}
