/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:33:35 by jprofit           #+#    #+#             */
/*   Updated: 2022/08/14 09:57:07 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_show_matrix(int row, int col, int matrix[row][col]);
void	ft_show_matrix_full(int matrix[6][6]);
int		ft_fill_matrix(int matrix[6][6]);
int		ft_arg_is_valid(int argc, char *argv[]);
void	ft_put_para(int matrix[6][6], char *argv[]);
void	ft_put_para_h(int matrix[6][6], char *argv[]);

int	main(int argc, char **argv)
{
	int	matrix[6][6];

	if (ft_arg_is_valid(argc, argv) != 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	ft_fill_matrix(matrix);
	ft_put_para(matrix, argv);
	ft_show_matrix(6, 6, matrix);
	return (0);
}
