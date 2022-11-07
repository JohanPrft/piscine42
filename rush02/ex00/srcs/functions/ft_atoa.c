/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 23:28:52 by hferraud          #+#    #+#             */
/*   Updated: 2022/08/21 23:33:23 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rush.h"

int	is_in_str(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	skip_to_number(char *nbr, int *i)
{
	int	sign;

	sign = 1;
	while (is_in_str(nbr[*i], " \t\v\n\f\r"))
		*i += 1;
	if (nbr[*i] == '-' || nbr[*i] == '+')
	{
		if (nbr[*i] == '-')
			sign = -1;
		*i += 1;
	}
	while (nbr[*i] == '0')
		*i += 1;
	return (sign);
}

char	*ft_atoa(char *nbr)
{
	char	*str;
	int		sign;
	int		i;
	int		j;

	i = 0;
	sign = skip_to_number(nbr, &i);
	j = i;
	while (nbr[i] >= '0' && nbr[i] <= '9')
		i++;
	if (sign == -1)
		i++;
	str = malloc((i - j + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	if (sign == -1)
		str[i++] = '-';
	while (nbr[j] >= '0' && nbr[j] <= '9')
		str[i++] = nbr[j++];
	str[i] = '\0';
	return (str);
}
