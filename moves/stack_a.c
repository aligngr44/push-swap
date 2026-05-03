/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:45:47 by algungor          #+#    #+#             */
/*   Updated: 2026/05/03 14:21:07 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	m_sa(t_stack **a)
{
	t_stack	*one;
	t_stack	*two;

	if (!a || !*a || !(*a)->next)
		return ;
	one = *a;
	two = (*a)->next;
	one->next = two->next;
	if (two->next)
		two->next->prev = one;
	two->next = one;
	two->prev = NULL;
	one->prev = two;
	*a = two;
}

void	m_ra(t_stack **a)
{
	t_stack	*one;
	t_stack	*lst;

	if (!a || !*a || !(*a)->next)
		return ;
	one = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	one->next = NULL;
	lst = stack_last(*a);
	lst->next = one;
	one->prev = lst;
}

void	m_rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*new_last;

	if (!a || !*a || !(*a)->next)
		return ;
	last = stack_last(*a);
	new_last = last->prev;
	new_last->next = NULL;
	last->next = *a;
	(*a)->prev = last;
	last->prev = NULL;
	*a = last;
}
