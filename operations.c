/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:41:16 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/04/18 17:41:21 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **lst, int stack) //123 -> 231
{
	t_stack	*tmp;

	if (!(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	ft_stklast(*lst)->next = tmp;
	tmp->next = NULL;
	if (stack)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	rra(t_stack **lst, int stack) //123 -> 312
{
	t_stack	*tmp;
	t_stack	*end;

	if (!(*lst)->next)
		return ;
	tmp = *lst;
	while (tmp->next->next)
		tmp = tmp->next;
	end = ft_stklast(*lst);
	ft_stklast(*lst)->next = *lst;
	tmp->next = NULL;
	*lst = end;
	if (stack)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	sa(t_stack **lst, int stack)
{
	t_stack	*tmp;

	if (!(*lst)->next)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	tmp->next = *lst;
	*lst = tmp;
	if (stack)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	pa(t_stack **a, t_stack **b, int stack)
{
	t_stack	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	if (stack)
		write(1, "pb\n", 3);
	else
		write(1, "pa\n", 3);
}
