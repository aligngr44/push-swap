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
	m_pa(a, b);
	write(1, "pa\n", 3);
}
void	pb(t_stack **a, t_stack **b)
{
	m_pb(a, b);
	write(1, "pb\n", 3);
}
