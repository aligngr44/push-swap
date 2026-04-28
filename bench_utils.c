/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algungor <algungor@student.42istanbul.com.t+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 19:44:29 by algungor          #+#    #+#             */
/*   Updated: 2026/04/27 19:44:32 by algungor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_putstr(char *s)
{
	while (*s)
		write(2, s++, 1);
}

void	bench_putnbr(int n)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		write(2, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		bench_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(2, &c, 1);
}

void	bench_put_percent(double disorder)
{
	int	scaled;
	int	frac;

	scaled = (int)(disorder * 10000.0 + 0.5);
	frac = scaled % 100;
	bench_putnbr(scaled / 100);
	write(2, ".", 1);
	if (frac < 10)
		write(2, "0", 1);
	bench_putnbr(frac);
	write(2, "%", 1);
}

void	bench_put_count(char *name, int count)
{
	bench_putstr("[bench] ");
	bench_putstr(name);
	bench_putstr(": ");
	bench_putnbr(count);
	bench_putstr("\n");
}

void	bench_put_strategy(t_bench *bench)
{
	if (bench->mode == 1)
		bench_putstr("simple, complexity: O(n^2)\n");
	else if (bench->mode == 2)
		bench_putstr("medium, complexity: O(n sqrt(n))\n");
	else if (bench->mode == 3)
		bench_putstr("complex, complexity: O(n log n)\n");
	else if (bench->disorder < 0.2)
		bench_putstr("adaptive, complexity: O(n^2)\n");
	else if (bench->disorder < 0.5)
		bench_putstr("adaptive, complexity: O(n sqrt(n))\n");
	else
		bench_putstr("adaptive, complexity: O(n log n)\n");
}
