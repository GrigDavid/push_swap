/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:16:22 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/05/07 16:21:35 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

static int	check_doubles(int *arr, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (arr[j] == arr[i])
			return (0);
		j++;
	}
	return (1);
}

static char	*strglue(char *s1, const char *s2)
{
	char	*res;
	char	*tmp;

	if (!s2)
		return (s1);
	tmp = ft_strjoin(s1, " ");
	if (!tmp)
		return (free(s1), NULL);
	res = ft_strjoin(tmp, s2);
	if (!res)
		return (free(s1), free(tmp), NULL);
	free(tmp);
	free(s1);
	return (res);
}

static char	**join_argv(int argc, char **argv)
{
	int		i;
	char	*str;
	char	**mat;

	str = (char *)malloc(1);
	if (!str)
		return (NULL);
	str[0] = 0;
	i = 0;
	while (i < argc - 1)
	{
		str = strglue(str, argv[++i]);
		if (!str)
			return (NULL);
	}
	mat = ft_split(str, ' ');
	if (!mat)
		return (free(str), NULL);
	free(str);
	return (mat);
}

int	*parser(int *argc, char **argv)
{
	int	i;
	int	*res;

	argv = join_argv(*argc, argv);
	if (!argv)
		return (NULL);
	*argc = 0;
	while (argv[*argc])
		(*argc)++;
	res = (int *)malloc(sizeof(int) * (*argc));
	if (!res)
		return (free_mat(argv, *argc), NULL);
	i = 0;
	while (i < *argc)
	{
		res[i] = alt_atoi(argv[i]);
		if (!check_doubles(res, i))
			return (free_mat(argv, *argc), free(res), NULL);
		if (res[i] == 0 && !check_zero(argv[i]))
			return (free_mat(argv, *argc), free(res), NULL);
		i++;
	}
	free_mat(argv, *argc);
	return (res);
}
