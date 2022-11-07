/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 09:04:14 by jprofit           #+#    #+#             */
/*   Updated: 2022/08/05 10:47:39 by jprofit          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(int c)
{
	write(1, &c, 1);
}

void	printall(int a, int b)
{
	putchar(a / 10 + 48);
	putchar(a % 10 + 48);
	putchar(' ');
	putchar(b / 10 + 48);
	putchar(b % 10 + 48);
	if (a != 98)
	{
		putchar(',');
		putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a / 10 <= 9)
	{
		while (b / 10 <= 9)
		{
			printall(a, b);
			b++;
		}
		a++;
		b = a + 1;
	}
}
