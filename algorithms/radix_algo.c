/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:42:55 by algungor          #+#    #+#             */
/*   Updated: 2026/05/03 14:45:28 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	radix_pass(t_stack **a, t_stack **b, int bit)
{
	int	size;

	size = stack_size(*a);
	while (size--)
	{
		if (get_bit((*a)->index, bit))
			ra(a);
		else
			pb(a, b);
	}
	while (*b)
		pa(a, b);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	max_index;

	if (stack_size(*a) <= 5)
	{
		sort_small(a, b);
		return ;
	}
	indexing(*a);
	max_index = get_all_bits(stack_size(*a) - 1);
	i = 0;
	while (i < max_index)
	{
		radix_pass(a, b, i);
		i++;
	}
}
