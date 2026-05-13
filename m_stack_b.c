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
	if (b)
	{
		bench_count(*b, op_sb);
		bench_write(*b, "sb\n", 3);
	}
	m_sb(b);
}

void	rb(t_stack **b)
{
	if (b)
	{
		bench_count(*b, op_rb);
		bench_write(*b, "rb\n", 3);
	}
	m_rb(b);
}

void	rrb(t_stack **b)
{
	if (b)
	{
		bench_count(*b, op_rrb);
		bench_write(*b, "rrb\n", 4);
	}
	m_rrb(b);
}
