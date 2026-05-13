/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_stack_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:46:49 by algungor          #+#    #+#             */
/*   Updated: 2026/04/27 17:47:03 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	if (a)
	{
		bench_count(*a, op_sa);
		bench_write(*a, "sa\n", 3);
	}
	m_sa(a);
}

void	ra(t_stack **a)
{
	if (a)
	{
		bench_count(*a, op_ra);
		bench_write(*a, "ra\n", 3);
	}
	m_ra(a);
}

void	rra(t_stack **a)
{
	if (a)
	{
		bench_count(*a, op_rra);
		bench_write(*a, "rra\n", 4);
	}
	m_rra(a);
}
