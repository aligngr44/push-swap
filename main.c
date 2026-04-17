// int main(int ac, char **av)
// {
//     char **ptr;
//     int i;
//     int arg_idx;

//     if (ac < 2) // Eğer hiç argüman yoksa program bir şey yazmadan kapanmalı [cite: 270]
//         return (0);

//     arg_idx = 1; // 0 program adıdır, 1'den başlıyoruz
//     while (arg_idx < ac)
//     {
//         ptr = ft_split(av[arg_idx], '.'); // Her bir argümanı boşluğa göre böl
//         i = 0;
//         while (ptr && ptr[i])
//         {
//             printf("%s\n", ptr[i]); // Sayıları gör
//             // Burada sayıları stack yapına (struct) ekleme mantığını kurmalısın
//             free(ptr[i]); // İşin bitince temizle [cite: 35]
//             i++;
//         }
//         free(ptr);
//         arg_idx++;
//     }
//     return (0);
// }
#include "push_swap.h"

static void	sort_small(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (!parse_input(&a, ac, av))
	{
		stack_clear(&a);
		ft_error();
		return (1);
	}
	if (!is_sorted(a))
		sort_small(&a, &b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}