#include "push_swap.h"

void	ra(t_list **lst, int stack) //123 -> 231
{
	t_list	*tmp;

	if (!(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	ft_lstlast(*lst)->next = tmp;
	tmp->next = NULL;
	if (stack)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	rra(t_list **lst, int stack) //123 -> 312
{
	t_list	*tmp;
	t_list	*end;

	if (!(*lst)->next)
		return ;
	tmp = *lst;
	while (tmp->next->next)
		tmp = tmp->next;
	end = ft_lstlast(*lst);
	ft_lstlast(*lst)->next = *lst;
	tmp->next = NULL;
	*lst = end;
	if (stack)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	sa(t_list **lst, int stack)
{
	t_list	*tmp;

	if (!(*lst)->next)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	tmp->next = *lst;
	*lst = tmp;
	if (stack)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	pa(t_list **a, t_list **b, int stack)
{
	t_list	*tmp;
	
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	if (stack)
		write(1, "pb\n", 3);
	else
		write(1, "pa\n", 3);
}
