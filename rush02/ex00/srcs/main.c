/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 23:48:15 by hferraud          #+#    #+#             */
/*   Updated: 2022/08/21 23:40:29 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_dict	*head;

	head = NULL;
	if (argc < 2 || argc > 3)
		return (ft_puterr("Error\n"));
	else if (!check_args(argv[argc - 1]))
		return (ft_puterr("Error\n"));
	else if (argc == 3)
		head = parse_dict(argv[1]);
	else
		head = parse_dict("numbers.dict.txt");
	if (head == NULL)
		return (ft_puterr("Dict Error\n"));
	if (!display_full_nbr(argv[argc - 1], head))
	{
		free_dict_list(head);
		return (ft_puterr("Dict Error\n"));
	}
	return (0);
}
