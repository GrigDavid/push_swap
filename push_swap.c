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

void    print_arr(int *arr, int len)
{
    int i;

    i = 0;
    while (i < len)
	{
		printf("%d\n", arr[i]);
	    i++;
	}
}

int *parser(int argc, char **argv)
{
	int	i;
	int	*res;

	i = 1;
	res = (int *)malloc(sizeof(int) * (argc - 1));
	if (!res)
		return (NULL);
	while (i < argc)
	{
		res[i - 1] = ft_atoi(argv[i]);
		if (res[i - 1] == 0 && argv[i][0] != '0')
		{
			free(res);
			return (NULL);
		}
		i++;
	}
	return (res);
}



int	main(int argc, char **argv)
{
	int *arr = parser(argc, argv);
	if (!arr)
	{
		write (1, "Gjvel es?\n", 10);
		return (0);
	}
	print_arr(arr, argc - 1);
	return (0);

}

// void	ra(int argc, char **argv)
// {
// 	char	*swap = argv[1];
// 	int		i;
	
// 	i = 2;
// 	while ()

// }

// void	rra

// void	push_swap(int argc, char **argv)
// {
//     char	**stack_a;
//     char	**stack_b;
//     int		a_len;
//     int		b_len;

// 	stack_a = (char **)malloc((argc - 1) + sizeof(char *));
// 	if (!stack_a)
// 		return ;
// 	stack_b = (char **)malloc((argc - 1) * sizeof(char *));
// 	if (!stack_b)
// 	{
// 		free(stack_a);
// 		return ;
// 	}
// 	a_len = argc - 1;
// 	b_len = 0;
// 	while (a_len > 0)
// 	{

// 	}
// }
