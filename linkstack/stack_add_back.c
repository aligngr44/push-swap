/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:45:04 by algungor          #+#    #+#             */
/*   Updated: 2026/04/27 13:45:08 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (!stack || !new_node)
		return ;
	if (!*stack) // Liste boşsa, yeni gelen artık listenin başıdır
	{
		*stack = new_node;
		return ;
	}
	last = stack_last(*stack);
	last->next = new_node; // Eskinin önü -> Yeni
	new_node->prev = last; // Yeninin arkası -> Eski [İşte prev burada!]
}
