/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 13:47:55 by algungor          #+#    #+#             */
/*   Updated: 2026/04/27 13:47:57 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol_limit(int sign)
{
	if (sign == -1)
		return (2147483648);
	return (2147483647);
}

int	ft_atol_overflows(long result, long limit, int digit)
{
	if (result > limit / 10)
		return (1);
	if (result == limit / 10 && digit > limit % 10)
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	long	result;
	long	limit;
	int		sign;
	int		digit;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	limit = ft_atol_limit(sign);
	while (str[i])
	{
		digit = str[i] - '0';
		if (ft_atol_overflows(result, limit, digit))
			return (2147483648);
		result = result * 10 + digit;
		i++;
	}
	return (result * sign);
}
