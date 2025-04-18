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