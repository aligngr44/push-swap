#include "push_swap.h"

void	min_push_to_b(t_stack **a, t_stack **b)
{
	int	min;
	int	pos;
	int	size;

	min = stack_min(*a);
	pos = find_position(*a, min);
	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while ((*a)->value != min)
			ra(a);
	}
	else
	{
		while ((*a)->value != min)
			rra(a);
	}
	pb(a, b);
}