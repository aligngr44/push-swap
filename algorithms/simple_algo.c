/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:42:51 by algungor          #+#    #+#             */
/*   Updated: 2026/04/27 13:45:02 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
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

void	simple_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size <= 1 || is_sorted(*a))
		return ;
	if (size == 2)
	{
		sort_two(a);
		return ;
	}
	while (stack_size(*a) > 3)
		min_push_to_b(a, b);
	sort_three(a);
	while (*b)
		pa(a, b);
}
