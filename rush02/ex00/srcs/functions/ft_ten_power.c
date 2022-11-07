/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_power.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 23:36:53 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/21 23:36:59 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rush.h"

char	*ft_ten_power(int power)
{
	int		i;
	char	*s;

	i = 1;
	if (power <= 0)
		return ("0");
	s = malloc(sizeof(char) * (power + 2));
	s[0] = '1';
	while (i <= power)
		s[i++] = '0';
	s[i] = '\0';
	return (s);
}
