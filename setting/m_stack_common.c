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
		bench_count(*a, op_ss);
	else if (b)
		bench_count(*b, op_ss);
	m_sa(a);
	m_sb(b);
	write(1, "ss\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	if (a && *a)
		bench_count(*a, op_rr);
	else if (b)
		bench_count(*b, op_rr);
	m_ra(a);
	m_rb(b);
	write(1, "rr\n", 3);
}

void	rrr(t_stack **a, t_stack **b)
{
	if (a && *a)
		bench_count(*a, op_rrr);
	else if (b)
		bench_count(*b, op_rrr);
	m_rra(a);
	m_rrb(b);
	write(1, "rrr\n", 4);
}
