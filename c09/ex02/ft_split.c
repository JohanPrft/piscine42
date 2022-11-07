/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:38:08 by jprofit           #+#    #+#             */
/*   Updated: 2022/08/25 10:57:29 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*ft_strcpy_index(const char *str_from, int start, int end)
{
	int		i;
	char	*str_to;

	str_to = malloc (sizeof(*str_to) * (end - start + 1));
	if (!str_to)
		return (NULL);
	i = 0;
	while (*str_from && start < end)
	{
		str_to[i++] = str_from[start++];
	}
	str_to[i] = '\0';
	return (str_to);
}

void	create_tab(char **tab, char *str, char *charset, int *nb_line)
{
	int		i;
	int		j;
	int		last_i;

	i = 0;
	j = 0;
	last_i = 0;
	while (str[i])
	{
		while (is_charset(str[i], charset))
			i++;
		if (!is_charset(str[i], charset) && str[i] != '\0')
			last_i = i;
		while (!is_charset(str[i], charset) && str[i] != '\0')
			i++;
		if ((is_charset(str[i], charset) || str[i] == '\0') && last_i != i)
			tab[j++] = ft_strcpy_index(str, last_i, i);
	}
	*nb_line = j;
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
	tab[nb_line] = 0;
	return (tab);
}
#include <stdio.h>

int main()
{
	int j;
	char **str;

	j  = 0;
	str = ft_split(".../coucou je suis split. si je marche je suis la deuxieme ligne .7/q4 je suis insuportable qje marche 1 fois sur deux //////////44444; je suis une nouvelle ligne ; en vrai si tu me rentre en premiere piscine c est pas mal 7 je tombe aussi en exam btw 4qq faut aussi me test avec des charset vide ///.. bon je te laisse bonne chance pour la piscine frero..///////....q44q;",".7/q4;");

	while(str[j])
		printf("===%s\n", str[j++]);
	free(str);

	printf("\n\n\noutput normal : \n===coucou je suis split\n=== si je marche je suis la deuxieme ligne \n=== je suis insuportable \n===je marche 1 fois sur deux \n=== je suis une nouvelle ligne \n=== en vrai si tu me rentre en premiere piscine c est pas mal \n=== je tombe aussi en exam btw \n=== faut aussi me test avec des charset vide \n=== bon je te laisse bonne chance pour la piscine frero");
}
