/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:41:38 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/04/18 17:41:39 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **lst)
{
	if ((*lst)->content < (*lst)->next->content)
	{
		if ((*lst)->next->content > (*lst)->next->next->content)
		{
			rra(lst, 1);
			if ((*lst)->content > (*lst)->next->content)
				sa(lst, 1);
		}
	}
	else if ((*lst)->content > (*lst)->next->content)
	{
		if ((*lst)->next->content > (*lst)->next->next->content)
		{
			ra(lst, 1);
			sa(lst, 1);
		}
		else if ((*lst)->next->content < (*lst)->next->next->content)
		{
			if ((*lst)->content < (*lst)->next->next->content)
				sa(lst, 1);
			else
				ra(lst, 1);
		}
	}
}
