/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium-algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigungor <bigungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:43:06 by algungor          #+#    #+#             */
/*   Updated: 2026/05/03 14:59:51 by bigungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	push_to_b_if_in_chunk(t_stack **a, t_stack **b, int start, int end)
{
	int	mid;

	mid = (start + end) / 2;
	if ((*a)->index >= start && (*a)->index <= end)
	{
		pb(a, b);
		if ((*b)->index < mid)
			rb(b);
	}
	else
		ra(a);
}

void	process_chunk(t_stack **a, t_stack **b, int start, int end)
{
	while (has_chunk_value(*a, start, end))
		push_to_b_if_in_chunk(a, b, start, end);
}

void	push_chunks_to_b(t_stack **a, t_stack **b)
{
	int size;
	int chunk;
	int start;
	int end;

	size = stack_size(*a);
	chunk = chunk_size(size);
	start = 0;
	end = chunk - 1;
	while (start < size)
	{
		if (end >= size)
			end = size - 1;
		process_chunk(a, b, start, end);
		start += chunk;
		end += chunk;
	}
}