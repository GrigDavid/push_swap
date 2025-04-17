#include "push_swap.h"

void	sort_three(t_list **lst)
{
	if ((*lst)->content < (*lst)->next->content && (*lst)->next->content > (*lst)->next->next->content) //132 231
	{
		rra(lst, 1); //213 123
		if ((*lst)->content > (*lst)->next->content) //213
			sa(lst, 1); //123
	}
	else if ((*lst)->content > (*lst)->next->content && (*lst)->next->content < (*lst)->next->next->content) //213 312
	{
		if ((*lst)->content < (*lst)->next->next->content) //213
			sa(lst, 1); //123
		else //312
			ra(lst, 1);
	}
	else if ((*lst)->content > (*lst)->next->content && (*lst)->next->content > (*lst)->next->next->content) //321
	{
		ra(lst, 1);
		sa(lst, 1);
	}
}

void	babshka(t_list **a, t_list **b)
{
	int	i;
	int	kuku;
	int	size;
	int	o_size;

	size = ft_lstsize(*a);
	i = 1;
	kuku = 0;
	o_size = size;
	ra(a, 1);
	
	while (size > 0)
	{
		if ((*a)->content < 26)
			pa(a, b, 1);
		else
			ra(a, 1);
		size--;
	}
	size = ft_lstsize(*a);
	while (size > 0)
	{
		if ((*a)->content < 51)
			pa(a, b, 1);
		else
			ra(a, 1);
		size--;
	}
	size = ft_lstsize(*a);
	while (size > 0)
	{
		if ((*a)->content < 76)
			pa(a, b, 1);
		else
			ra(a, 1);
		size--;
	}
	size = ft_lstsize(*a);
	while (size > 3)
	{
		if ((*a)->content == 100)
			ra(a,1);
		else
			pa(a, b, 1);
		size = ft_lstsize(*a);
	}
	sort_three(a);
	while (*b)
	{
		while ((*a)->content - (*b)->content != 1)
			ra(a, 1);
		pa(b, a, 0);
	}
	//sarqel funkcia vor kgtni myus stackum amenamotiky
	// ft_lstiter(*a, ft_putnbr);
	// ft_printf(" ->a\n");
	// ft_lstiter(*b, ft_putnbr);
	// ft_printf(" ->b\n");
}
