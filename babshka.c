/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   babshka.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:41:27 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/04/18 17:41:28 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	closest(int a, t_list *b)
{
	int		min;
	int		i;
	int		min_i;
	int		size;

	min = INT_MAX;
	size = ft_lstsize(b);
	i = 0;
	while (b)
	{
		if  (a - b->content < min)
		{
			min = a - b->content;
			min_i = i;
		}
		i++;
		b = b->next;
	}
	if (min_i > size / 2)
		min_i = -(size - min_i);
	return (min_i);
}

int	min_val(t_list *a)
{
	int	min;

	min = a->content;
	while (a)
	{
		if (a->content < min)
		{
			min = a->content;
		}
		a = a->next;
	}
	return (min);
}

void	babshka(t_list **a, t_list **b)
{
	int	n;
	int	k;

	k  = 14;
	n = 1;
	while (*a)
	{
		if ((*a)->content <= n)
		{
			pa(a, b, 1);
			n++;
		}
		else if ((*a)->content <= n + k)
		{
			pa(a, b, 1);
			ra(b, 0);
			n++;
		}
		else
		{
			ra(a, 1);
		}
	}
	//sort_three(a);
	n = 100;
	while (*b)
	{
		r = closest(n, *b);
		while (r > 0)
		{
			ra(b, 0);
			r--;
		}
		while (r < 0)
		{
			rra(b, 0);
			r++;
		}
		pa (b, a, 0);
	}
}
