/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:21:39 by jprofit           #+#    #+#             */
/*   Updated: 2022/08/23 14:40:52 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	verif_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	in_base(char bit, char *base)
{
	while (*base)
	{
		if (bit == *base)
			return (1);
		base++;
	}
	return (0);
}

int	int_in_base(char bit, char *base)
{
	int	i;

	i = 0;
	while (bit != base[i])
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	sign;
	int	l_base;

	l_base = verif_base(base);
	if (l_base < 2)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	sign = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	res = 0;
	while (*str && in_base(*str, base))
	{
		res = (res * l_base) + int_in_base(*str, base);
		str++;
	}
	return (sign * res);
}
