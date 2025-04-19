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

void	babshka(t_list **a, t_list **b)
{
	int	i;
	int	size;
	int	o_size;
	int	chunks;

	//ankap
	int k;
	int mov;

	chunks = 2;
	size = ft_lstsize(*a);
	i = 0;
	o_size = size;
	while (i < chunks / 2)
	{
		size = ft_lstsize(*a);
		while (size > 0)
		{
			if ((*a)->content < (o_size * (i + 1)) / chunks && (*a)->content > (o_size * i / chunks))
			{
				pa(a, b, 1);
				if (size < 99 &&(*b)->content < (*b)->next->content)
						ra(b, 0);
			}
			else
				ra(a, 1);
			size--;
		}
		i++;
	}
	while (*b)
	{
		k = 0;
		mov = closest((*a)->content, *b);
		if (mov > 0)
		{
			while (k < mov)
			{
				ra(b, 0);
				k++;
			}
		}
		else if (mov < 0)
		{
			while (k > mov)
			{
				rra(b, 0);
				k--;
			}
		}
		pa(b, a, 0);
		ra(a, 1);
	}
	size = 100;
	while (i < chunks)
	{
		size = ft_lstsize(*a);
		while (size > 0)
		{
			if ((*a)->content < (o_size * (i + 1)) / chunks && (*a)->content > (o_size * i / chunks))
			{
				pa(a, b, 1);
				if (size < 99 &&(*b)->content < (*b)->next->content)
						ra(b, 0);
			}
			else
				ra(a, 1);
			size--;
		}
		i++;
	}
	sort_three(a);
	while (*b)
	{
		i = 0;
		size = closest((*a)->content, *b);
		if (size > 0)
		{
			while (i < size)
			{
				ra(b, 0);
				i++;
			}
		}
		else if (size < 0)
		{
			while (i > size)
			{
				rra(b, 0);
				i--;
			}
		}
		pa(b, a, 0);
	}
}
