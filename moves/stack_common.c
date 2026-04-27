/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_common.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:46:07 by algungor          #+#    #+#             */
/*   Updated: 2026/04/27 13:46:11 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	m_ss(t_stack **a, t_stack **b)
{
	m_sa(a);
	m_sb(b);
}

void	m_rr(t_stack **a, t_stack **b)
{
	m_ra(a);
	m_rb(b);
}

void	m_rrr(t_stack **a, t_stack **b)
{
	m_rra(a);
	m_rrb(b);
}
