/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:48:30 by algungor          #+#    #+#             */
/*   Updated: 2026/05/06 17:38:16 by algungor         ###   ########.fr       */
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

static void	setup_bench(t_stack *a, t_bench *bench, t_option option)
{
	if (option.bench != 0)
	{
		bench_init(bench, option.mode, disorder(a));
		bench->active = option.bench;
		bench_attach(a, bench);
	}
} 

static void	print_bench(t_bench *bench, t_option option)
{
	if (option.bench != 0)
		bench_print(bench);
}

static void	execute_sort(t_stack **a, t_stack **b, t_option option)
{
	if (!is_sorted(*a))
		run_sort(a, b, option.mode);
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
	setup_bench(a, &bench, option);
	execute_sort(&a, &b, option);
	print_bench(&bench, option);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
