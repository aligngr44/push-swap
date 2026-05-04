/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:47:10 by algungor          #+#    #+#             */
/*   Updated: 2026/04/27 13:47:14 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position(t_stack *stack, int value)
{
	int		position;
	t_stack	*tmp;

	tmp = stack;
	position = 0;
	while (tmp)
	{
		if (tmp->value == value)
			return (position);
		tmp = tmp->next;
		position++;
	}
	return (1);
}
