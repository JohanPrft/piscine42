/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:44:13 by jprofit           #+#    #+#             */
/*   Updated: 2022/08/07 18:33:27 by jprofit          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	printif(int x_b, int y_b, int x, int y)
{
	if ((x_b == 1 && y_b == 1) || (x_b == x && y_b == 1)
		|| (x_b == 1 && y_b == y) || (x_b == x && y_b == y))
		ft_putchar('o');
	else if ((1 < x_b && x_b < x) && (y_b == 1 || y_b == y))
		ft_putchar('-');
	else if ((1 < y_b && y_b < y) && (x_b == 1 || x_b == x))
		ft_putchar('|');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	x_b;
	int	y_b;

	if (x < 1 || y < 1)
	{
		return ;
	}
	y_b = 1;
	while (y_b <= y)
	{
		x_b = 1;
		while (x_b <= x)
		{
			printif(x_b, y_b, x, y);
			x_b++;
		}
		ft_putchar('\n');
		y_b++;
	}
}
