/* bench.c */

#include "push_swap.h"

void	bench_init(t_bench *bench, int active)
{
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->total = 0;
	bench->active = active;
}

void	bench_count(t_bench *bench, char *op)
{
	if (!bench || !bench->active)
		return ;
	bench->total++;
	if (!ft_strcmp(op, "sa"))
		bench->sa++;
	else if (!ft_strcmp(op, "sb"))
		bench->sb++;
	else if (!ft_strcmp(op, "ss"))
		bench->ss++;
	else if (!ft_strcmp(op, "pa"))
		bench->pa++;
	else if (!ft_strcmp(op, "pb"))
		bench->pb++;
	else if (!ft_strcmp(op, "ra"))
		bench->ra++;
	else if (!ft_strcmp(op, "rb"))
		bench->rb++;
	else if (!ft_strcmp(op, "rr"))
		bench->rr++;
	else if (!ft_strcmp(op, "rra"))
		bench->rra++;
	else if (!ft_strcmp(op, "rrb"))
		bench->rrb++;
	else if (!ft_strcmp(op, "rrr"))
		bench->rrr++;
}

void	bench_print(t_bench *b, double disorder,
	char *strategy, char *complexity)
{
	if (!b || !b->active)
		return ;
	ft_dprintf(2, "[bench] disorder: %.2f%%\n", disorder * 100);
	ft_dprintf(2, "[bench] strategy: %s\n", strategy);
	ft_dprintf(2, "[bench] complexity: %s\n", complexity);
	ft_dprintf(2, "[bench] total operations: %d\n", b->total);
	ft_dprintf(2, "[bench] sa: %d\n", b->sa);
	ft_dprintf(2, "[bench] sb: %d\n", b->sb);
	ft_dprintf(2, "[bench] ss: %d\n", b->ss);
	ft_dprintf(2, "[bench] pa: %d\n", b->pa);
	ft_dprintf(2, "[bench] pb: %d\n", b->pb);
	ft_dprintf(2, "[bench] ra: %d\n", b->ra);
	ft_dprintf(2, "[bench] rb: %d\n", b->rb);
	ft_dprintf(2, "[bench] rr: %d\n", b->rr);
	ft_dprintf(2, "[bench] rra: %d\n", b->rra);
	ft_dprintf(2, "[bench] rrb: %d\n", b->rrb);
	ft_dprintf(2, "[bench] rrr: %d\n", b->rrr);
}
