/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:46:04 by algungor          #+#    #+#             */
/*   Updated: 2026/04/27 13:46:06 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	m_sb(t_stack **b)
{
	t_stack	*one;
	t_stack	*two;

	if (!b || !*b || !(*b)->next) // stack boşsa veya tek elemanlıysa işlem yok
		return ;
	one = *b;
	two = one->next;
	one->next = two->next;
	if (two->next) // üçüncü eleman varsa prev bağlantısını düzelt
		two->next->prev = one;
	two->next = one;
	two->prev = NULL; // yeni head
	one->prev = two;
	*b = two; // stack başını güncelle
}

void	m_rb(t_stack **b)
{
	t_stack	*one;
	t_stack	*lst;

	if (!b || !*b || !(*b)->next) // rotate için en az 2 eleman gerekir
		return ;
	one = *b;       // eski head
	*b = one->next; // yeni head
	(*b)->prev = NULL;
	one->next = NULL;
	lst = stack_last(*b); // son elemanı bul
	lst->next = one;      // eski head'i sona koy
	one->prev = lst;
}

void	m_rrb(t_stack **b)
{
	t_stack	*last;
	t_stack	*new_last;

	if (!b || !*b || !(*b)->next) // reverse rotate için kontrol
		return ;
	last = stack_last(*b); // son eleman
	new_last = last->prev; // yeni son eleman
	new_last->next = NULL;
	last->next = *b; // eski head'i last'in arkasına bağla
	(*b)->prev = last;
	last->prev = NULL; // last yeni head olacak
	*b = last;
}
