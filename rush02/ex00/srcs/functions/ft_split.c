/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 22:06:50 by hferraud          #+#    #+#             */
/*   Updated: 2022/08/21 23:33:32 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rush.h"

void	ft_strpcpy(char *dest, char *src, int i, int j)
{
	int	k;

	k = 0;
	while (i < j)
	{
		dest[k] = src[i];
		k++;
		i++;
	}
	dest[k] = '\0';
}

int	is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	find_next_wrd(char *str, char *charset, int *index)
{
	int		i;

	i = 0;
	while (charset[i] == '\0' && str[*index])
		*index += 1;
	while (str[*index])
	{
		i = 0;
		while (is_in_charset(str[*index + i], charset))
			i++;
		if (i != 0)
			return (*index + i);
		*index += 1;
	}
	return (*index);
}

void	ft_insert(char **split_strs, char *str, char *charset)
{
	int		index;
	int		next_index;
	int		last_i;
	int		ct_wrd;

	last_i = 0;
	ct_wrd = 0;
	index = 0;
	while (str[index])
	{
		next_index = find_next_wrd(str, charset, &index);
		if (last_i != index)
		{
			split_strs[ct_wrd] = malloc((index - last_i + 1) * sizeof(char));
			ft_strpcpy(split_strs[ct_wrd], str, last_i, index);
			ct_wrd++;
		}
		index = next_index;
		last_i = index;
	}
	split_strs[ct_wrd] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**split_strs;
	int		nb_wrd;
	int		index;
	int		previous_index;
	int		next_index;

	index = 0;
	previous_index = 0;
	nb_wrd = 0;
	while (str[index])
	{
		next_index = find_next_wrd(str, charset, &index);
		if (previous_index != index)
		{
			nb_wrd++;
		}
		index = next_index;
		previous_index = index;
	}
	split_strs = malloc((nb_wrd + 1) * sizeof(char *));
	ft_insert(split_strs, str, charset);
	return (split_strs);
}
