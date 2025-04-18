#include "push_swap.h"

int	closest(int a, t_list **b)
{
	int	i;
	int	len;
	t_list	*start;

	start = *b;
	len = ft_lstsize(*b);
	i = 0;
	while (*b)
	{
		if (a - ((*b)->content) == 1)
		{
			*b = start;
			if (i > (len / 2))
			{
				return (i - ft_lstsize(*b));
			}
			else
			{
				return (i);
			}
		}
		i++;
		*b = (*b)->next;
	}
	*b = start;
	return (0);
}

void	babshka(t_list **a, t_list **b)
{
	int	i;
	int	size;
	int	o_size;
	int	chunks;

	chunks = 5;
	size = ft_lstsize(*a);
	i = 1;
	o_size = size;
	while (i < chunks)
	{
		while (size > 2+o_size * (chunks - i) / chunks)
		{
			if ((*a)->content < (o_size * i) / chunks)
			{
				size--;
				pa(a, b, 1);
			}
			else
				ra(a, 1);
		}
		i++;
	}
	while (size > 3)
	{
		if ((*a)->content <= o_size - 3)
		{
			size--;
			pa(a, b, 1);
		}
		else
			ra(a, 1);
	}
	sort_three(a);
	while (*b)
	{
		i = 0;
		size = closest((*a)->content, b);
		if (size > 0)
		{
			while (i < size)
			{
				ra(b, 0);
				i++;
			}
		}
		else if(size < 0)
		{
			while (i > size)
			{
				rra(b, 0);
				i--;
			}
		}
		pa(b, a, 0);
	}
}
