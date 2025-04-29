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


void	roll_to_min(t_stack **lst)
{
	int	min;
	int	i;
	int	min_cor;
	t_stack	*tmp;

	i = 0;
	min_cor = 0;
	tmp = *lst;
	min = tmp->content;
	while (tmp)
	{
		if (tmp->content < min)
		{
			min_cor = i;
			min = tmp->content;
		}
		i++;
		tmp = tmp->next;
	}
	if (min_cor < ft_stksize(*lst) / 2)
	{
		while (min_cor-- > 0)
			ra(lst, 1);
	}
	else
	{
		while (min_cor++ < ft_stksize(*lst))
			rra(lst, 1);
	}
}

void	sort_n(t_stack **a, t_stack **b, int n)
{
	int	i;

	i = 3;
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

int	set_range(int n)
{
	if (n < 20)
		return (2);
	else if (n <= 50)
		return (5); // hardcode kanes
	return ((3 * n + 900) / 80);
}

int	closest(t_stack *b)
{
	int		max;
	int		i;
	int		max_i;
	int		size;

	max = INT_MIN;
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

int	min_val(t_stack *a)
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

void	refill_a(t_stack **a, t_stack **b)
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

void	fill_b(t_stack **a, t_stack **b)
{
	int	n;
	int	k;

	if (ft_stksize(*a) == 2)
	{
		if ((*a)->content > (*a)->next->content)
			sa(a, 1);
		return ;
	}
	if (ft_stksize(*a) <= 5)
	{
		sort_n(a, b, ft_stksize(*a));
		return ;
	}
	k = set_range(ft_stksize(*a));
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
