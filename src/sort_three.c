/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:17:12 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/05/07 16:21:40 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
