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