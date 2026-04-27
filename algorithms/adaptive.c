/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:42:57 by algungor          #+#    #+#             */
/*   Updated: 2026/04/27 13:43:04 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	disorder(t_stack *a)
{
	int		mistake;
	int		total;
	t_stack	*i;
	t_stack	*j;

	mistake = 0;
	total = 0;
	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
				mistake++;
			total++;
			j = j->next;
		}
		i = i->next;
	}
	return ((double)mistake / total);
}
void	adaptive_sort(t_stack **a, t_stack **b)
{
	double	d;
	int		size;

	size = stack_size(*a);
	if (size <= 5)
	{
		simple_sort(a, b);
		return ;
	}
	d = disorder(*a);
	if (d < 0.2)
		simple_sort(a, b);
	else if (d < 0.5)
		chunk_sort(a, b);
	else
		radix_sort(a, b);
}
