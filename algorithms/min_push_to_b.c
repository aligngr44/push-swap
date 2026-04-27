/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_push_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:44:26 by algungor          #+#    #+#             */
/*   Updated: 2026/04/27 13:44:29 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
