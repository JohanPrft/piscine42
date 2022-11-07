/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   johan2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:04:39 by jprofit           #+#    #+#             */
/*   Updated: 2022/08/14 09:52:11 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_is_letter(char c);
void	ft_putchar(char c);
void	ft_put_para_h(int matrix[6][6], char *argv[]);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	ft_put_para(int matrix[6][6], char *argv[])
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 0;
	k = 0;
	while (j < 6)
	{
		while (i < 5)
		{
			if (ft_is_number (argv[1][k]))
			{
				matrix[j][i] = argv[1][k] - '0';
				i++;
			}
			k++;
		}
		i = 1;
		j += 5;
	}
	ft_put_para_h(matrix, argv);
}

void	ft_put_para_h(int matrix[6][6], char *argv[])
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 0;
	k = 0;
	while (j < 6)
	{
		while (i < 5)
		{
			if (ft_is_number (argv[1][k]))
			{
				matrix[i][j] = argv[1][k] - '0';
				i++;
			}
			k++;
		}
		i = 1;
		j += 5;
	}
}
