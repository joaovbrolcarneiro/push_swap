#include "../../inc/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*highest_value_node;

	highest_value_node = find_max(*a);
	if (highest_value_node == *a)
		ra(a, false);
	else if ((*a)->next == highest_value_node)
		rra(a, false);
	if ((*a)->content > (*a)->next->content)
		sa(a, false);
}