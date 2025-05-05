/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refill_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:16:49 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/05/05 17:16:59 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_steps(t_stack *b)
{
	int		max;
	int		i;
	int		max_i;
	int		size;

	max = b->content;
	max_i = 0;
	size = ft_stksize(b);
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

void	refill_a(t_stack **a, t_stack **b)
{
	int	n;

	while (*b)
	{
		n = max_steps(*b);
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
