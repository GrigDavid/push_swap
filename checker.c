/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:36:31 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/05/07 16:44:09 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*arr;
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	if (argc < 2)
		return (0);
	arr = parser(&argc, argv);
	if (!arr)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (!arr_cpy(arr, argc))
	{
		free(arr);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	a = lst_ise(arr, argc);
	//anavart(voshiban charac)
}






