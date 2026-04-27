/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium-algo2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:43:24 by algungor          #+#    #+#             */
/*   Updated: 2026/04/27 15:06:12 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_max_index(t_stack *stack)
// Bu fonksiyon B içindeki en büyük index’i bulacak.
{
	int max;

	if (!stack)
		return (-1);
	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	find_position_by_index(t_stack *stack, int index)
// Bu da o index’in B içinde kaçıncı sırada olduğunu bulacak
{
	int pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

void	rotate_b_to_top(t_stack **b, int target_index)
{
	int pos;
	int size;

	pos = find_position_by_index(*b, target_index);
	size = stack_size(*b);
	if (pos <= size / 2)
	{
		while ((*b)->index != target_index)
			rb(b);
	}
	else
	{
		while ((*b)->index != target_index)
			rrb(b);
	}
}

void	push_back_to_a(t_stack **a, t_stack **b)

{
	int max;

	while (*b)
	{
		max = stack_max_index(*b);
		rotate_b_to_top(b, max);
		pa(a, b);
	}
}

void	chunk_sort(t_stack **a, t_stack **b)
{
	indexing(*a);
	push_chunks_to_b(a, b);
	push_back_to_a(a, b);
}
