/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigungor <bigungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 14:52:24 by bigungor          #+#    #+#             */
/*   Updated: 2026/05/03 14:53:42 by bigungor         ###   ########.fr       */
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
