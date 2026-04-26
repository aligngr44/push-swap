#include "push_swap.h"
// #include <stdio.h>
// void	print_stack(t_stack *stack, char name)
// {
// 	printf("Stack %c: ", name);
// 	while (stack)
// 	{
// 		printf("%d", stack->value);
// 		if (stack->next)
// 			printf(" ");
// 		stack = stack->next;
// 	}
// 	printf("\n");
// }
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		mode;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (!parse_input(&a, &mode, ac, av))
	{
		write(2, "Error\n", 6);
		stack_clear(&a);
		return (1);
	}
	if (is_sorted(a) && b == NULL)
	{
		stack_clear(&a);
		return (0);
	}
	// print_stack(a, 'A');
	// print_stack(b, 'B');

	//indexing(a); /////// !!!!!!!!!!! incelenecek !!!!!!!!!
	if (mode == 1)
		simple_sort(&a, &b);
	else if (mode == 2)
		chunk_sort(&a, &b);
	else if (mode == 3)
		radix_sort(&a, &b);
	else if (mode == 4)
		adaptive_sort(&a, &b);
	else
		adaptive_sort(&a, &b);

	// print_stack(a, 'A');
	// print_stack(b, 'B');
	stack_clear(&a);
	stack_clear(&b);

	return (0);
}