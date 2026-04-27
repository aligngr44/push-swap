/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:45:17 by algungor          #+#    #+#             */
/*   Updated: 2026/04/27 13:45:21 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_clear(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next; // Bir sonrakini güvenli yere al
		free(*stack);         // Mevcut olanı temizle
		*stack = tmp;         // Bir sonrakine geç
	}
	*stack = NULL; // İşi garantiye alalım
}
