/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:46:04 by algungor          #+#    #+#             */
/*   Updated: 2026/05/03 14:21:11 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	m_sb(t_stack **b)
{
	t_stack	*one;
	t_stack	*two;

	if (!b || !*b || !(*b)->next)
		return ;
	one = *b;
	two = one->next;
	one->next = two->next;
	if (two->next)
		two->next->prev = one;
	two->next = one;
	two->prev = NULL;
	one->prev = two;
	*b = two;
}

void	m_rb(t_stack **b)
{
	t_stack	*one;
	t_stack	*lst;

	if (!b || !*b || !(*b)->next)
		return ;
	one = *b;
	*b = one->next;
	(*b)->prev = NULL;
	one->next = NULL;
	lst = stack_last(*b);
	lst->next = one;
	one->prev = lst;
}

void	m_rrb(t_stack **b)
{
	t_stack	*last;
	t_stack	*new_last;

	if (!b || !*b || !(*b)->next)
		return ;
	last = stack_last(*b);
	new_last = last->prev;
	new_last->next = NULL;
	last->next = *b;
	(*b)->prev = last;
	last->prev = NULL;
	*b = last;
}
