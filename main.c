/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:48:30 by algungor          #+#    #+#             */
/*   Updated: 2026/04/27 13:48:36 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_sort(t_stack **a, t_stack **b, int mode)
{
	if (mode == 1)
		simple_sort(a, b);
	else if (mode == 2)
		chunk_sort(a, b);
	else if (mode == 3)
		radix_sort(a, b);
	else if (mode == 4)
		adaptive_sort(a, b);
	else
		adaptive_sort(a, b);
}

static int	main_error(t_stack **a)
{
	write(2, "Error\n", 6);
	stack_clear(a);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_bench		bench;
	t_option	option;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (!parse_input(&a, &option, ac, av))
		return (main_error(&a));
	if (!a)
		return (0);
	if (option.bench != 0)
	{
		bench_init(&bench, option.mode, disorder(a));
		bench_attach(a, &bench);
	}
	if (!is_sorted(a))
		run_sort(&a, &b, option.mode);
	if (option.bench != 0)
		bench_print(&bench);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
