/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:17:49 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/02/01 16:56:32 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr(int n)
{
	char	zero;

	zero = '0';
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-n);
		return ;
	}
	if (n < 10)
	{
		zero += n;
		write(1, &zero, 1);
		return ;
	}
	ft_putnbr(n / 10);
	zero += n % 10;
	write (1, &zero, 1);
}
