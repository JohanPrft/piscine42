/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:27:37 by edboutil          #+#    #+#             */
/*   Updated: 2022/08/06 16:16:33 by edboutil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	x_b;
	int	y_b;

	if (x < 1 || y < 1)
		return ;
	y_b = 1;
	while (y_b <= y)
	{
		x_b = 1;
		while (x_b <= x)
		{
			if ((x_b == 1 && y_b == 1) || (x_b == x && y_b == 1))
				ft_putchar('A');
			else if ((x_b == 1 && y_b == y) || (x_b == x && y_b == y))
				ft_putchar('C');
			else if ((x_b > 1 && x_b < x) && (y_b > 1 && y_b < y))
				ft_putchar(' ');
			else
				ft_putchar('B');
			x_b++;
		}
		ft_putchar('\n');
		y_b++;
	}
}
