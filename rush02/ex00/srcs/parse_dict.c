/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:35:50 by hferraud          #+#    #+#             */
/*   Updated: 2022/08/21 23:34:19 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush.h"

#define BUF_SIZE 4096

int	dict_length(char *file_name)
{
	int		fd;
	char	buf[1];
	int		read_ret;
	int		length;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	length = 0;
	read_ret = 1;
	while (read_ret)
	{
		read_ret = read(fd, buf, 1);
		if (read_ret == -1)
			return (-1);
		length++;
	}
	if (close(fd) == -1)
		return (-1);
	return (length);
}

char	*dict_to_str(char *file_name)
{
	int		fd;
	char	buf[BUF_SIZE];
	int		read_ret;
	char	*strret;
	int		i;

	if (dict_length(file_name) == -1)
		return (NULL);
	strret = malloc(dict_length(file_name) + 1);
	fd = open(file_name, O_RDONLY);
	if (fd == -1 || strret == NULL)
		return (NULL);
	i = 0;
	read_ret = 1;
	while (read_ret)
	{
		read_ret = read(fd, buf, 1);
		if (read_ret == -1)
			return (NULL);
		strret[i++] = *buf;
	}
	if (close(fd) == -1)
		return (NULL);
	strret[i] = 0;
	return (strret);
}

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

t_dict	*str_to_list(char *str)
{
	t_dict	*head;
	char	**strs;
	char	*key;
	int		i;
	int		j;

	head = NULL;
	strs = ft_split(str, "\n");
	i = 0;
	while (strs[i])
	{
		j = 0;
		key = ft_atoa(strs[i]);
		while (strs[i][j] != ':')
			j++;
		j++;
		while (strs[i][j] == ' ')
			j++;
		push_dict_elem(&head, key, ft_strdup(strs[i] + j));
		i++;
	}
	free_strs(strs);
	return (head);
}

t_dict	*parse_dict(char *file_name)
{
	t_dict	*head;
	char	*str;

	str = dict_to_str(file_name);
	if (str == NULL)
		return (NULL);
	head = str_to_list(str);
	return (head);
}
