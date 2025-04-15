#include "push_swap.h"

void	frik(t_list **a, t_list **b)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(*a);
	while (i < size)
	{
		if ((*a)->content > 2 * size / 3)
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
}