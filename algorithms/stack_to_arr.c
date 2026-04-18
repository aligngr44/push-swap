#include "push_swap.h"

int	*stack_to_array(t_stack *stack, int size)
{
	t_stack	*a;
	int		*arr;
	int		i;

	if (!stack || size <= 0)
		return (NULL);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	a = stack;
	i = 0;
	while (a)
	{
		arr[i] = a->value;
		a = a->next;
		i++;
	}
	return (arr);
}
