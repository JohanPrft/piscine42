/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:35:39 by jprofit           #+#    #+#             */
/*   Updated: 2022/08/11 19:09:47 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// AsciiToInteger
#include <ctype.h>
#include <unistd.h>

int	ft_is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_is_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	long	res;
	long	sign;

	sign = 1;
	res = 0;
	while (ft_is_whitespace(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_is_number(*str))
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (sign * res);
}
