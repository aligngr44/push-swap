#include "push_swap.h"

int	parse_input(t_stack **a, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!parse_arg(a, av[i]))
			return (0);
		i++;
	}
	return (1);
}