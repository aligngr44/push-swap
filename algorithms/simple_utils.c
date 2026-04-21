#include "push_swap.h"
void sort_two(t_stack **a)
{
    if((*a)->value > (*a)->next->value)
        sa(a);
}
void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;

	if (first > second && second < third && first < third) // 2 1 3
		sa(a);
	else if (first > second && second > third) // 3 2 1
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third) // 3 1 2
		ra(a);
	else if (first < second && second > third && first < third) // 1 3 2
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third) // 2 3 1
		rra(a);
}

void sort_four(t_stack **a, t_stack **b)
{
    min_push_to_b(a, b);
    sort_three(a);
    pa(a,b);
}

void sort_five(t_stack **a, t_stack **b)
{
	min_push_to_b(a, b);
	sort_four(a,b);
	pa(a,b);
}

void	simple_sort(t_stack **a, t_stack **b)
{

	while (stack_size(*a) > 3)
	{
		min_push_to_b(a, b); // sen yazacaksın (ra / rra seçimi)
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}
