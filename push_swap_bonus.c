/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:43:02 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/05/12 14:43:03 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exec(t_stack **a, t_stack **b, char *str)
{
	if (!ft_strncmp(str, "ra\n", 3))
		return (ra(a, 2), 1);
	else if (!ft_strncmp(str, "rra\n", 4))
		return (rra(a, 2), 1);
	else if (!ft_strncmp(str, "rb\n", 3))
		return (ra(b, 2), 1);
	else if (!ft_strncmp(str, "rrb\n", 4))
		return (rra(b, 2), 1);
	else if (!ft_strncmp(str, "rr\n", 3))
		return (ra(a, 2), ra(b, 2), 1);
	else if (!ft_strncmp(str, "rrr\n", 4))
		return (rra(a, 2), rra(b, 2), 1);
	else if (!ft_strncmp(str, "pa\n", 3))
		return (pa(b, a, 2), 1);
	else if (!ft_strncmp(str, "pb\n", 3))
		return (pa(a, b, 2), 1);
	else if (!ft_strncmp(str, "sa\n", 3))
		return (sa(a, 2), 1);
	else if (!ft_strncmp(str, "sb\n", 3))
		return (sa(b, 2), 1);
	else if (!ft_strncmp(str, "ss\n", 3))
		return (sa(a, 2), sa(b, 2), 1);
	return (0);
}

static void	reader(t_stack **a, t_stack **b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (!exec(a, b, str))
		{
			ft_putstr_fd("Error\n", 2);
			free(str);
			return ;
		}
		free(str);
	}
	if (is_sorted(*a) && !(*b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	int		*arr;
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	if (argc < 2)
		return (0);
	arr = parser(&argc, argv);
	if (!arr)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (!arr_cpy(arr, argc))
	{
		free(arr);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	a = lst_ise(arr, argc);
	reader(&a, &b);
	ft_stkclear(&a);
	ft_stkclear(&b);
}
