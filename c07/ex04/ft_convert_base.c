/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:08:03 by jprofit           #+#    #+#             */
/*   Updated: 2022/08/23 14:46:27 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	verif_base(char *base);
int	ft_atoi_base(char *str, char *base);
int	in_base(char bit, char *base);

char	*ft_strrev(char *str)
{
	int		size;
	int		i;
	char	temp;

	size = 0;
	while (str[size])
		size++;
	size--;
	i = 0;
	if (str[0] == '-')
		i++;
	while (i < size -1 / 2)
	{
		temp = str[i];
		str[i] = str[size];
		str[size] = temp;
		i++;
		size--;
	}
	return (str);
}

char	*ft_itoa(int nbr, char *base_to, int len)
{
	char	*res;
	int		i;
	long	nb;

	i = 0;
	nb = nbr;
	res = malloc(sizeof(*res) * (len + 2));
	if (res == NULL)
		return (NULL);
	if (nb < 0)
	{
		res[i++] = '-';
		nb *= -1;
	}
	if (nb == 0)
		res[i++] = base_to[0];
	while (nb != 0)
	{
		res[i++] = base_to[nb % len];
		nb /= len;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		len;
	int		i;
	long	nb;
	char	*res;

	if (!*nbr || !verif_base(base_from) || !verif_base(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	i = 0;
	while (base_to[i])
		i++;
	len = i;
	res = ft_itoa (nb, base_to, len);
	res = ft_strrev (res);
	return (res);
}
