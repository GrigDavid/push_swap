#include "push_swap.h"

void	ra(t_list **lst)
{
	t_list	*tmp;

	if (!(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	ft_lstlast(*lst)->next = tmp;
	tmp->next = NULL;
	//write(1, "ra\n", 3);
}

void	rra(t_list **lst)
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
	//write(1, "rra\n", 4);
}

void	sa(t_list **lst)
{
	t_list	*tmp;

	if (!(*lst)->next)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	tmp->next = *lst;
	*lst = tmp;
	//write(1, "sa\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	//write(1, "pa\n", 3);
}