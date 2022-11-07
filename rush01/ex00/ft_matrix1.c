/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   johan.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:33:47 by jprofit           #+#    #+#             */
/*   Updated: 2022/08/14 09:57:29 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_show_matrice(int row, int col, int matrice[row][col]);

int	ft_is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

void	ft_show_matrix(int row, int col, int matrice[row][col])
{
	int	x;
	int	y;

	x = 1;
	while (x < row - 1)
	{
		y = 1;
		while (y < col - 1)
		{
			ft_putchar(' ');
			ft_putchar('0' + matrice[x][y]);
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}

void	ft_show_matrix_full(int matrix[6][6])
{
	int	x;
	int	y;

	x = 0;
	while (x < 6)
	{
		y = 0;
		while (y < 6)
		{
			ft_putchar(' ');
			ft_putchar('0' + matrix[x][y]);
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}

void	ft_fill_matrix(int matrix[6][6])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 6)
	{
		while (j < 6)
		{
			matrix[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

int	ft_arg_is_valid(int argc, char *argv[])
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (argc != 2)
		return (1);
	while (argv[1][i] != '\0')
	{
		if ((argv[1][i] < '1' || argv[1][i] > '4')
			&& !ft_is_whitespace(argv[1][i]))
			return (1);
		if (argv[1][i] > '0' && argv[1][i] < '5'
			&& (ft_is_whitespace(argv[1][i + 1])
				|| argv[1][i + 1] == '\0'))
			n++;
		i++;
	}
	if (n != 16)
		return (1);
	else
		return (0);
}
