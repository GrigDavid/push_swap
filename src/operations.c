/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:16:15 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/05/12 14:14:57 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **lst, int stack)
{
	t_stack	*tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	ft_stklast(*lst)->next = tmp;
	tmp->next = NULL;
	if (stack == 1)
		write(1, "ra\n", 3);
	else if (stack == 0)
		write(1, "rb\n", 3);
}

void	rra(t_stack **lst, int stack)
{
	t_stack	*tmp;
	t_stack	*end;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	while (tmp->next->next)
		tmp = tmp->next;
	end = ft_stklast(*lst);
	ft_stklast(*lst)->next = *lst;
	tmp->next = NULL;
	*lst = end;
	if (stack == 1)
		write(1, "rra\n", 4);
	else if (stack == 0)
		write(1, "rrb\n", 4);
}

void	sa(t_stack **lst, int stack)
{
	t_stack	*tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	tmp->next = *lst;
	*lst = tmp;
	if (stack == 1)
		write(1, "sa\n", 3);
	else if (stack == 0)
		write(1, "sb\n", 3);
}

void	pa(t_stack **a, t_stack **b, int stack)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	if (stack == 1)
		write(1, "pb\n", 3);
	else if (stack == 0)
		write(1, "pa\n", 3);
}
