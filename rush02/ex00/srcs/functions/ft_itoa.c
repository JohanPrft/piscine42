/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 13:48:45 by jprofit           #+#    #+#             */
/*   Updated: 2022/08/21 23:33:29 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rush.h"

int	size_int(unsigned int nb)
{
	int	size;

	size = 0;
	while (nb > 0)
	{	
		size++;
		nb /= 10;
	}	
	return (size);
}

char	*ft_pos_itoa(unsigned int nb)
{
	int		i;
	int		len;
	char	*buff;

	i = 0;
	if (nb == 0)
		return ("0");
	len = size_int(nb);
	buff = malloc(sizeof(*buff) * (len + 1));
	if (buff == NULL)
		return (NULL);
	i = len - 1;
	while (nb > 0)
	{
		buff[i] = nb % 10 + '0';
		i--;
		nb /= 10;
	}
	buff[len] = '\0';
	return (buff);
}
