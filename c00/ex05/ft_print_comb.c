/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:37:59 by jprofit           #+#    #+#             */
/*   Updated: 2022/08/05 08:19:38 by jprofit          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	print_comb(char x, char y, char z)
{
	putchar(x);
	putchar(y);
	putchar(z);
	if (x != '7')
	{
		putchar(',');
		putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char	x;
	char	y;
	char	z;

	x = '0';
	y = '1';
	z = '2';
	while (x <= '7')
	{
		while (y <= '8')
		{
			while (z <= '9')
			{
				print_comb(x, y, z);
				z++;
			}
			y++;
			z = y + 1;
		}
		x++;
		y = x;
	}
}
