#include "push_swap.h"

void	babshka(t_list **a, t_list **b)
{
	int	i;
	int	kuku;

	i = 1;
	kuku = 0;
	
	ra(a, 1);
	
	while (*a)
	{
		if ((*a)->content == i)
		{
			if (kuku)
			{
				i++;
				kuku--;
			}
			pa(a, b, 1);
			i++;
		}
		else if ((*a)->content == i + 1)
		{
			pa(a, b, 1);
			ra(b, 0);
			kuku++;
		}
		else
		{
			ra(a, 1);
		}
	}
	while (*b)
	{
		
		if ((*b)->content < ft_lstlast(*b)->content)
		{
			rra(b, 0);
		}
		pa(b , a, 0);
	}
	
	// ft_lstiter(*a, ft_putnbr);
	// ft_printf(" ->a\n");
	// ft_lstiter(*b, ft_putnbr);
	// ft_printf(" ->b\n");
}