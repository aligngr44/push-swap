/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:45:10 by algungor          #+#    #+#             */
/*   Updated: 2026/05/03 14:28:02 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_add_front(t_stack **stack, t_stack *new_node)
{
	if (!stack || !new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
		return ;
	}
	new_node->next = *stack;
	(*stack)->prev = new_node;
	*stack = new_node;
	new_node->prev = NULL;
}
