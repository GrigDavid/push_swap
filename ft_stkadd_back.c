/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:14:40 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/05/05 17:14:42 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stkadd_back(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
		ft_stklast(*lst)->next = new;
}
