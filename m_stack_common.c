/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_stack_common.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:47:05 by algungor          #+#    #+#             */
/*   Updated: 2026/04/27 13:47:08 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack **b)
{
	if (a && *a)
	{
		bench_count(*a, op_ss);
		bench_write(*a, "ss\n", 3);
	}
	else if (b)
	{
		bench_count(*b, op_ss);
		bench_write(*b, "ss\n", 3);
	}
	m_sa(a);
	m_sb(b);
}

void	rr(t_stack **a, t_stack **b)
{
	if (a && *a)
	{
		bench_count(*a, op_rr);
		bench_write(*a, "rr\n", 3);
	}
	else if (b)
	{
		bench_count(*b, op_rr);
		bench_write(*b, "rr\n", 3);
	}
	m_ra(a);
	m_rb(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	if (a && *a)
	{
		bench_count(*a, op_rrr);
		bench_write(*a, "rrr\n", 4);
	}
	else if (b)
	{
		bench_count(*b, op_rrr);
		bench_write(*b, "rrr\n", 4);
	}
	m_rra(a);
	m_rrb(b);
}
