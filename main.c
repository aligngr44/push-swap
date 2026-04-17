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
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	b = NULL;
	a = NULL;
	if (ac != 6)
	{
		printf("Usage: ./push_swap n1 n2 n3\n");
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		stack_add_back(&a, stack_new(atoi(av[i])));
		i++;
	}
	printf("Before: ");
	print_stack(a);

	sort_five(&a, &b);

	printf("After:  ");
	print_stack(a);
	return (0);
}