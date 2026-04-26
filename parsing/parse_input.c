#include "push_swap.h"

int	parse_input(t_stack **a, int *mode, int ac, char **av)
{
	int	i;

	i = 1;
	*mode = 0;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "--simple"))
			*mode = 1;
		else if (!ft_strcmp(av[i], "--medium"))
			*mode = 2;
		else if (!ft_strcmp(av[i], "--adaptive"))
			*mode = 4;
		else if (!ft_strcmp(av[i], "--complex"))
			*mode = 3;
		else if (!parse_arg(a, av[i]))
			return (0);
		i++;
	}
	return (1);
}