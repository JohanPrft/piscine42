/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcart <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 09:39:36 by vcart             #+#    #+#             */
/*   Updated: 2022/08/14 09:52:29 by vcart            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_missing_on_line(int k, int matrix[6][6], int i)
{
	int	j;

	j = 1;
	while (j < 6)
	{
		if (matrix[i][j] == k)
			return (0);
		j++;
	}
	return (1);
}

int	ft_missing_on_col(int k, int matrix[6][6], int j)
{
	int	i;

	i = 1;
	while (i < 6)
	{
		if (matrix[i][j] == k)
			return (0);
		i++;
	}
	return (1);
}

int	ft_valid_on_line(int k, int matrix[6][6], int i)
{
	int	j;
	int	show;

	j = 1;
	show = 1;
	while (j < 5)
	{
		if (matrix[i][j] <= matrix[i + 1][j])
			show++;
		j++;
	}
	if (show == matrix[i][0])
		return (1);
	return (0);
}

int	ft_valid_on_col(int k, int matrix[6][6], int j)
{
	int	i;
	int	show;

	i = 1;
	show = 1;
	while (i < 5)
	{
		if (matrix[i][j] <= matrix[i][j + 1])
			show++;
		i++;
	}
	if (show == matrix[0][j])
		return (1);
	return (0);
}
