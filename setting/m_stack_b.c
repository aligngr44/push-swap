/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_stack_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:46:58 by algungor          #+#    #+#             */
/*   Updated: 2026/04/27 13:47:02 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **b)
{
	m_sb(b);
	write(1, "sb\n", 3);
}
void	rb(t_stack **b)
{
	m_rb(b);
	write(1, "rb\n", 3);
}
void	rrb(t_stack **b)
{
	m_rrb(b);
	write(1, "rrb\n", 4);
}
