/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:38:08 by jprofit           #+#    #+#             */
/*   Updated: 2022/08/23 15:49:42 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_charset(const char c, const char *charset)
{
	int	i;

	i = 0;
	while (charset[i] && c != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	nb_seg(char *str, char *charset)
{
	int	i;
	int	n_line;

	i = 0;
	n_line = 0;
	while (str[i])
	{
		while (is_charset(str[i], charset))
			i++;
		if (!is_charset(str[i], charset) && str[i] != '\0')
			n_line++;
		while (!is_charset(str[i], charset) && str[i] != '\0')
			i++;
	}
	return (n_line);
}

void	ft_strcpy_index(char *str_to, const char *str_from, int start, int end)
{
	while (*str_from && start < end)
	{
		*str_to = str_from[start];
		str_to++;
		start++;
	}
	*str_to = '\0';
}

int	create_tab(char **tab, char *str, char *charset, int *nb_line)
{
	int		i;
	int		last_i;

	i = 0;
	last_i = 0;
	while (str[i])
	{
		if (!is_charset(str[i], charset))
		{	
			last_i = i;
			i++;
		}
		while (!is_charset(str[i], charset) && str[i] != '\0')
			i++;
		tab[*nb_line] = malloc(sizeof(*tab) * (i - last_i + 1));
		if (tab[*nb_line] == NULL)
			return (0);
		ft_strcpy_index(tab[*nb_line], str, last_i, i);
		while (is_charset(str[i], charset))
			i++;
		(*nb_line)++;
	}
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	int		nb_line;
	char	**tab;

	nb_line = nb_seg(str, charset);
	tab = malloc(sizeof(tab) * (nb_line + 1));
	if (tab == NULL)
		return (NULL);
	nb_line = 0;
	create_tab(tab, str, charset, &nb_line);
	tab[nb_line] = malloc(sizeof(*tab));
	if (tab[nb_line] == NULL)
		return (NULL);
	tab[nb_line][0] = '\0';
	return (tab);
}
