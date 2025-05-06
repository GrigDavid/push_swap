/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:16:30 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/05/06 14:24:49 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int	is_sorted(t_stack *lst)
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
	if (!is_sorted(a))
		fill_b(&a, &b);
	ft_stkclear(&a);
	ft_stkclear(&b);
	return (0);
}
