/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:15:29 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/05/07 16:16:38 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_stkclear(t_stack **lst)
{
	t_stack	*p;

	if (!*lst || !lst)
		return ;
	while (*lst)
	{
		p = (*lst)->next;
		free(*lst);
		*lst = p;
	}
}
