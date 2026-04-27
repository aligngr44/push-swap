/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium-algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:43:06 by algungor          #+#    #+#             */
/*   Updated: 2026/04/27 13:43:22 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_unindexed_min(t_stack *stack)
{
	t_stack	*min;

	min = NULL;
	while (stack)
	{
		if (stack->index == -1)
		{
			if (min == NULL)
				min = stack;
			else if (stack->value < min->value)
				min = stack;
		}
		stack = stack->next;
	}
	return (min);
}

void	indexing(t_stack *stack)
{
	t_stack	*min;
	int		i;

	i = 0;
	min = find_unindexed_min(stack);
	while (min)
	{
		min->index = i;
		i++;
		min = find_unindexed_min(stack);
	}
}

int	chunk_size(int size)
{
	if (size <= 10)
		return (3);
	else if (size <= 50)
		return (7);
	else if (size <= 100)
		return (15);
	else if (size <= 500)
		return (30);
	return (45);
}

int	has_chunk_value(t_stack *a, int start, int end)
{
	while (a)
	{
		if (a->index >= start && a->index <= end)
			return (1);
		a = a->next;
	}
	return (0);
}

void	push_chunks_to_b(t_stack **a, t_stack **b)
{
	int	size;
	int	chunksize;
	int	start;
	int	end;
	int	mid;

	size = stack_size(*a);
	chunksize = chunk_size(size);
	start = 0;
	end = chunksize - 1;
	while (*a)
	{
		if (end >= size)
			end = size - 1;
		mid = (start + end) / 2;
		while (has_chunk_value(*a, start, end))
		{
			if ((*a)->index >= start && (*a)->index <= end)
			{
				pb(a, b);
				if ((*b)->index < mid)
					rb(b);
			}
			else
				ra(a);
		}
		start += chunksize;
		end += chunksize;
	}
}
