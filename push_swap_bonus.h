/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <dgrigor2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:16:39 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/05/12 14:40:55 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h" 
# include <limits.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_stknew(int content);
int		ft_stksize(t_stack *lst);
t_stack	*ft_stklast(t_stack *lst);
void	ft_stkadd_back(t_stack **lst, t_stack *new);
void	ft_stkclear(t_stack **lst);
t_stack	*lst_ise(int *arr, int len);
void	sort(int *arr, int len);
void	normalise(int *a, int *b, int len);
int		*parser(int *argc, char **argv);
void	ra(t_stack **lst, int stack);
void	rra(t_stack **lst, int stack);
void	sa(t_stack **t_stack, int stack);
void	pa(t_stack **a, t_stack **b, int stack);
void	fill_b(t_stack **a, t_stack **b);
void	sort_three(t_stack **lst);
int		check_sorted(t_stack *lst);
void	refill_a(t_stack **a, t_stack **b);
int		alt_atoi(const char *str);
int		arr_cpy(int *arr, int len);
void	free_mat(char **arr, int i);
int		is_sorted(t_stack *lst);

#endif
