/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:52:03 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/02/01 20:14:30 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **arr, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(arr[j]);
		j++;
	}
	free(arr);
}

void	ft_fill(char **arr, const char *s, int words, char c)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	j = 0;
	while (i < words)
	{
		while (s[j] == c)
			j++;
		t = j;
		while (s[t] != c && s[t])
			t++;
		arr[i] = ft_substr(s, j, t - j);
		if (!arr[i])
			ft_free(arr, j);
		j = t;
		i++;
	}
	arr[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		words;
	int		i;

	i = 0;
	words = 0;
	if (s[0] != c && s[0])
		words++;
	while (s[i])
		if (s[i++] == c)
			if (s[i] != c && s[i])
				words++;
	arr = (char **)malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	ft_fill(arr, s, words, c);
	return (arr);
}
