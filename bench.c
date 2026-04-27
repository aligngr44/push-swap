/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 19:44:29 by algungor          #+#    #+#             */
/*   Updated: 2026/04/27 19:44:32 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_init(t_bench *bench, int mode, double disorder)
{
	int	i;

	i = 0;
	bench->active = 1;
	bench->total = 0;
	bench->mode = mode;
	bench->disorder = disorder;
	while (i < 11)
		bench->op[i++] = 0;
}

void	bench_attach(t_stack *stack, t_bench *bench)
{
	while (stack)
	{
		stack->bench = bench;
		stack = stack->next;
	}
}

void	bench_count(t_stack *stack, t_bench_op op)
{
	t_bench	*bench;

	if (!stack || !stack->bench || !stack->bench->active)
		return ;
	bench = stack->bench;
	bench->total++;
	bench->op[op]++;
}

void	bench_print(t_bench *bench)
{
	if (!bench || !bench->active)
		return ;
	bench_putstr("[bench] disorder: ");
	bench_put_percent(bench->disorder);
	bench_putstr("\n[bench] strategy: ");
	bench_put_strategy(bench);
	bench_put_count("total", bench->total);
	bench_put_count("sa", bench->op[op_sa]);
	bench_put_count("sb", bench->op[op_sb]);
	bench_put_count("ss", bench->op[op_ss]);
	bench_put_count("pa", bench->op[op_pa]);
	bench_put_count("pb", bench->op[op_pb]);
	bench_put_count("ra", bench->op[op_ra]);
	bench_put_count("rb", bench->op[op_rb]);
	bench_put_count("rr", bench->op[op_rr]);
	bench_put_count("rra", bench->op[op_rra]);
	bench_put_count("rrb", bench->op[op_rrb]);
	bench_put_count("rrr", bench->op[op_rrr]);
}
