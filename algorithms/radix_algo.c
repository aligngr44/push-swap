#include "push_swap.h"

int	get_bit(int index, int bit)
{
	return ((index >> bit) & 1);
}

int	get_all_bits(int max_index)
{
	int	bit;

	bit = 0;
	while (max_index >> bit)
		bit++;
	return (bit);
}

void	radix_sort(t_stack **a, t_stack **b)
{
    int i;
    int max_index;
    int size;

    indexing(*a);
    max_index = get_all_bits(stack_size(*a) - 1);

    i = 0;
    while(i < max_index)
    {
        size = stack_size(*a);
        while(size--)
        {
            if(get_bit((*a)->index, i))
                ra(a);
            else
                pb(a, b);
        }
        while(*b)
            pa(a, b);
        i++;
    }
}