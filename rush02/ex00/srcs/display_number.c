/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 10:46:43 by hferraud          #+#    #+#             */
/*   Updated: 2022/08/21 23:32:59 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush.h"

int	check_parsed_int(struct s_int *nbr_head, t_dict *dict_head)
{
	t_dict	*dict_iterator;
	int		flag;

	flag = 1;
	while (nbr_head && flag == 1)
	{
		dict_iterator = dict_head;
		flag = 0;
		while (dict_iterator && flag == 0)
		{
			if (ft_strcmp(nbr_head->number, dict_iterator->key) == 0)
				flag = 1;
			dict_iterator = dict_iterator->next;
		}
		nbr_head = nbr_head->next;
	}
	return (flag);
}

void	display_dict_key(char *nbr, t_dict *head)
{
	while (head)
	{
		if (ft_strcmp(nbr, head->key) == 0)
			ft_putstr(head->data);
		head = head->next;
	}
}

int	display_full_nbr(char *nbr, t_dict *dict_head)
{
	struct s_int	*nbr_head;

	nbr_head = parse_int(nbr);
	if (check_parsed_int(nbr_head, dict_head) == 0)
		return (0);
	while (nbr_head)
	{
		display_dict_key(nbr_head->number, dict_head);
		if (nbr_head->next)
			ft_putstr(" ");
		nbr_head = nbr_head->next;
	}
	free_nbr_list(nbr_head);
	ft_putstr("\n");
	return (1);
}
