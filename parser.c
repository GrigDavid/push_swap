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

static int	check_zero(char *str)
{
	if (!ft_strncmp(str, "0", 2))
		return (1);
	else if (!ft_strncmp(str, "+0", 3))
		return (1);
	else if (!ft_strncmp(str, "-0", 3))
		return (1);
	return (0);
}

int	check_dubles(int *arr, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (arr[j] == arr[i])
			return(0);
		j++;
	}
	return(1);
}

int	*parser(int argc, char **argv)
{
	int	i;
	int	*res;

	i = 0;
	argc--;
	res = (int *)malloc(sizeof(int) * argc);
	if (!res)
		return (NULL);
	while (i < argc)
	{
		res[i] = ft_atoi(argv[i + 1]);
		if (!check_dubles(res, i))
			return (free(res), NULL);
		if (res[i] == 0 && !check_zero(argv[i + 1]))
			return (free(res), NULL);
		i++;
	}
	return (res);
}


static char	*strglue(char *s1, const char *s2)
{
	char	*res;
	int		i;
	int		j;	

	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	j = 0;
	res[i + j] = ' ';
	while (s2[++j])
		res[i + j] = s2[j];
	res[i + j] = '\0';
	free(s1);
	return (res);
}

char	**join_argv(int argc, char **argv)
{
	int	i;
	char	*res;
	char	**mat;

	res = (char *)malloc(1);
	if (!res)
		return (NULL);
	res[0] = 0;
	i = 0;
	while (i < argc - 1)
	{
		res = strglue(res, argv[++i]);
		if (!res)
			return (NULL);
	}
	mat = ft_split(res, ' ');
	if (!mat)
		return (free(res), NULL);
	free(res);
	return(mat);
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
