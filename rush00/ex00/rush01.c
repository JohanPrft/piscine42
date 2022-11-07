/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:13:51 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/07 17:12:35 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#define CORNER_1 '/'
#define CORNER_2 '\\'
#define BORDER '*'
#define FILL ' '

void	ft_putchar(char c);

void	printif(int mcol, int mline, int col, int line)
{
	if (
		(mline == 1 && mcol == 1)
		|| (
			(
				(line == 1 && col == 1)
				|| (line == mline && col == mcol)
			)
			&& (mcol != 1 || line != mline)
			&& !(mline == 1 && col == mcol)
		)
	)
		ft_putchar(CORNER_1);
	else if (
		(line == mline && col == 1)
		|| (line == 1 && col == mcol)
	)
		ft_putchar(CORNER_2);
	else if (
		(line > 1 && line < mline)
		&& (col > 1 && col < mcol)
	)
		ft_putchar(FILL);
	else
		ft_putchar(BORDER);
}

void	rush(int x, int y)
{
	int	x_s;
	int	y_s;

	x_s = 1;
	y_s = 1;
	if (x < 1 || y < 1)
		return ;
	while (y_s <= y)
	{
		while (x_s <= x)
		{
			printif(x, y, x_s, y_s);
			x_s++;
		}
		x_s = 1;
		y_s++;
		ft_putchar('\n');
	}
}
