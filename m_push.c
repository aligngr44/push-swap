/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:46:45 by algungor          #+#    #+#             */
/*   Updated: 2026/04/27 13:46:48 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	if (b)
	{
		bench_count(*b, op_pa);
		bench_write(*b, "pa\n", 3);
	}
	m_pa(a, b);
}

void	pb(t_stack **a, t_stack **b)
{
	if (a)
	{
		bench_count(*a, op_pb);
		bench_write(*a, "pb\n", 3);
	}
	m_pb(a, b);
}
