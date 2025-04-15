#include "push_swap.h"

int	puchur(t_list *lst)
{
	int	min;
	
	min = lst->content;
	while (lst)
	{
		if (lst->content < min)
			min = lst->content;
		lst = lst->min;
	}
	return (min);
}

void	frik(t_list **a, t_list **b)
{
	int	i;
	int	size;
	int	margin;

	margin = puchur(*a) - 1;
	i = 0;
	size = ft_lstsize(*a);
	ft_printf("\n\nsize: %d\n\n", size);
	while (i < size)
	{
		if ((*a)->content > 2 * size / 3 + margin)
		{
			ra(a);
		}
		else if ((*a)->content > size / 3)
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
	int	size;

	size = ft_lstsize(*a);
	//while (ft_lstsize(*a) > 2)
	frik(a, b);
	frik(a, b);
}