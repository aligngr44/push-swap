/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:46:27 by algungor          #+#    #+#             */
/*   Updated: 2026/04/27 13:46:29 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_arg(t_stack **a, char *arg)
{
	char	**split;
	int		i;

	split = ft_split(arg, ' ');
	if (!split || !split[0])
		return (0);
	i = 0;
	while (split[i])
	{
		if (!add_number_to_stack(a, split[i]))
		{
			free_split(split);
			return (0);
		}
		i++;
	}
	free_split(split);
	return (1);
}
