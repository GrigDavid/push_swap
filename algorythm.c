/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:14:31 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/05/05 17:14:32 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_val(t_stack *a)
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

static void	roll_to_min(t_stack **lst)
{
	int		min;
	int		min_cor;
	t_stack	*tmp;

	min_cor = 0;
	tmp = *lst;
	min = min_val(tmp);
	while (tmp->content != min)
	{
		min_cor++;
		tmp = tmp->next;
	}
	if (min_cor < ft_stksize(*lst) / 2)
	{
		while (min_cor-- > 0)
			ra(lst, 1);
		return ;
	}
	while (min_cor++ < ft_stksize(*lst))
		rra(lst, 1);
}

static void	sort_n(t_stack **a, t_stack **b, int n)
{
	int	i;

	i = 3;
	if (ft_stksize(*a) == 2)
	{
		sa(a, 1);
		return ;
	}
	while (i < n)
	{
		roll_to_min(a);
		pa(a, b, 1);
		i++;
	}
	sort_three(a);
	i = 3;
	while (i < n)
	{
		pa(b, a, 0);
		i++;
	}
}

static int	set_range(int n)
{
	if (n < 20)
		return (2);
	else if (n <= 50)
		return (5); // hardcode kanes
	return ((3 * n + 900) / 80);
}

void	fill_b(t_stack **a, t_stack **b)
{
	int	n;
	int	k;

	if (ft_stksize(*a) <= 5)
	{
		sort_n(a, b, ft_stksize(*a));
		return ;
	}
	k = set_range(ft_stksize(*a));
	n = 1;
	while (*a)
	{
		if ((*a)->content <= n + k)
		{
			pa(a, b, 1);
			if ((*b)->content > n)
				ra(b, 0);
			n++;
		}
		else
			ra(a, 1);
	}
	refill_a(a, b);
}
