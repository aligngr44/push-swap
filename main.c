#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	print_stack(t_stack *stack, char name)
{
	printf("Stack %c: ", name);
	while (stack)
	{
		printf("%d", stack->value);
		if (stack->next)
			printf(" ");
		stack = stack->next;
	}
	printf("\n");
}

// int	main(int ac, char **av)
// {
// 	t_stack	*a;
// 	t_stack	*b;
// 	int		i;

// 	a = NULL;
// 	b = NULL;
// 	i = 1;
// 	while (i < ac)
// 	{
// 		stack_add_back(&a, stack_new(atoi(av[i])));
// 		i++;
// 	}
// 	indexing(a);

// 	printf("Before:\n");
// 	print_stack(a, 'A');
// 	print_stack(b, 'B');

// 	/* BURAYI KENDİ MEDIUM FONKSİYON ADINLA DEĞİŞTİR */
// 	chunk_sort(&a, &b);

// 	printf("\nAfter:\n");
// 	print_stack(a, 'A');
// 	print_stack(b, 'B');

// 	if (is_sorted(a) && b == NULL)
// 		printf("\nRESULT: OK\n");
// 	else
// 		printf("\nRESULT: KO\n");

// 	stack_clear(&a);
// 	stack_clear(&b);
// 	return (0);
// }

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (!parse_input(&a, ac, av))
	{
		ft_error();
		stack_clear(&a);
		return (1);
	}
	print_stack(a, 'A');
	print_stack(b, 'B');
	if (is_sorted(a))
	{
		stack_clear(&a);
		return (0);
	}
	size = stack_size(a);
	if (size == 2)
		sort_two(&a);
	else if (size == 3)
		sort_three(&a);
	else if (size == 4)
		sort_four(&a, &b);
	else if (size == 5)
		sort_five(&a, &b);
	else
		simple_sort(&a, &b);
	print_stack(a, 'A');
	print_stack(b, 'B');
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}