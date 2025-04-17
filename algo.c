#include "push_swap.h"

void	sort_three(t_list **lst)
{
	if ((*lst)->content < (*lst)->next->content && (*lst)->next->content > (*lst)->next->next->content) //132 231
	{
		rra(lst); //213 123
		if ((*lst)->content > (*lst)->next->content) //213
			sa(lst); //123
	}
	else if ((*lst)->content > (*lst)->next->content && (*lst)->next->content < (*lst)->next->next->content) //213 312
	{
		if ((*lst)->content > (*lst)->next->next->content) //213
			sa(lst); //123
		else //312
			ra(lst);
	}
	else if ((*lst)->content > (*lst)->next->content && (*lst)->next->content > (*lst)->next->next->content) //321
	{
		ra(lst);
		sa(lst);
	}
}

void	roll_to_min(t_list **lst)
{
	int	min;
	int	i;
	int	min_cor;
	t_list	*tmp;

	i = 0;
	min_cor = 0;
	tmp = *lst;
	min = tmp->content;
	while (tmp)
	{
		if (tmp->content < min)
		{
			min_cor = i;
			min = tmp->content;
		}
		i++;
		tmp = tmp->next;
	}
	if (min_cor < ft_lstsize(*lst) / 2)
	{
		while (min_cor-- > 0)
			ra(lst);
	}
	else
	{
		while (min_cor++ < ft_lstsize(*lst))
			rra(lst);
	}
}

void	sort_n(t_list **a, t_list **b, int n)
{
	int	i;

	i = 3;
	while (i < n)
	{
		roll_to_min(a);
		pa(a, b);
		i++;
	}
	sort_three(a);
	i = 3;
	while (i < n)
	{
		pa(b, a);
		i++;
	}
}

int	puchur(t_list *lst, int size)
{
	int	min;
	int	i;
	
	i = 0;
	min = lst->content;
	while (i++ < size)
	{
		if (lst->content < min)
			min = lst->content;
		lst = lst->next;
	}
	return (min);
}

void	frik(t_list **a, t_list **b)
{
	int	i;
	int	size;
	int	margin;
	
	size = ft_lstsize(*a);
	margin = puchur(*a, size) - 1;
	i = 0;
	//ft_printf("\n\nmargin: %d\n\n", margin);
	while (i < size)
	{
		if ((*a)->content > 2 * size / 3 + margin)
		{
			ra(a);
		}
		else if ((*a)->content > size / 3 + margin)
		{
			pa(a, b);
		}
		else
		{
			pa(a, b);
			ra(b);
		}
		i++;
	}
}

void	alt_frik(t_list **a, t_list **b, int size)
{
	int	i;
	int	margin;

	margin = puchur(*a, size) - 1;
	i = 0;
	//ft_printf("\n\nmargin: %d\n\n", margin);
	while (i < size)
	{
		if ((*a)->content > 2 * size / 3 + margin)
		{
			ra(a);
		}
		else if ((*a)->content > size / 3 + margin)
		{
			pa(a, b);
		}
		else
		{
			pa(a, b);
			ra(b);
		}
		i++;
	}
}

void	algo(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) > 5)
	{
		frik(a, b);
		algo(a, b);
	
	
	
	
	}
	sort_n(a, b, ft_lstsize(*a));
	ft_lstiter(*a, ft_putnbr);
	ft_printf(" ->a\n");
	ft_lstiter(*b, ft_putnbr);
	ft_printf(" ->b\n");




	// frik(a, b);
	// ft_lstiter(*a, ft_putnbr);
	// ft_printf("\n");
	// ft_lstiter(*b, ft_putnbr);
	// ft_printf("\n");
}