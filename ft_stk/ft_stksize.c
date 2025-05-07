/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stksize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:15:51 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/05/07 16:17:11 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_stksize(t_stack *lst)
{
	int		i;
	t_stack	*p;

	p = lst;
	i = 1;
	if (!lst)
		return (0);
	while (p->next != 0)
	{
		i++;
		p = p->next;
	}
	return (i);
}
