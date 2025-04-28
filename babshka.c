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

int	set_range(int n)
{
	if (n < 20)
		return (2);
	else if (n <= 50)
		return (5); // hardcode kanes
	return ((3 * n + 900) / 80);
}

int	closest(t_list *b)
{
	int		max;
	int		i;
	int		max_i;
	int		size;

	max = INT_MIN;
	size = ft_lstsize(b);
	i = 0;
	while (b)
	{
		if (b->content > max)
		{
			max = b->content;
			max_i = i;
		}
		i++;
		b = b->next;
	}
	if (max_i > size / 2)
		max_i = -(size - max_i);
	return (max_i);
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

void	refill_a(t_list **a, t_list **b)
{
	int	n;

	while (*b)
	{
		n = closest(*b);
		while (n > 0)
		{
			ra(b, 0);
			n--;
		}
		while (n < 0)
		{
			rra(b, 0);
			n++;
		}
		pa (b, a, 0);
	}
}

void	fill_b(t_list **a, t_list **b)
{
	int	n;
	int	k;

	k = set_range(ft_lstsize(*a));
	n = 1;
	while (*a)
	{
		if ((*a) && (*a)->content <= n)
		{			
			pa(a, b, 1);
			ra(b, 0);
			n++;
		}
		else if ((*a)->content <= n + k)
		{
			pa(a, b, 1);
			n++;
		}
		else
			ra(a, 1);
	}
	refill_a(a, b);
}