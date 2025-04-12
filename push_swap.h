/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:25:17 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/04/09 13:25:19 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include "ft_printf.h"
# include <stdlib.h>

int		*parser(int argc, char **argv);
void	normalise(int *a, int *b, int len);
void	sort(int *arr, int len);

#endif
