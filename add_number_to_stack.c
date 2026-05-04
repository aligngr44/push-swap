/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_number_to_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:46:17 by algungor          #+#    #+#             */
/*   Updated: 2026/04/27 13:46:18 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_number_to_stack(t_stack **a, char *token)
{
	long	num;

	if (!is_number_string(token))
		return (0);
	num = ft_atol(token);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	if (the_same(*a, (int)num))
		return (0);
	stack_add_back(a, stack_new((int)num));
	return (1);
}
