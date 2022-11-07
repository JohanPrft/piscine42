/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 21:06:19 by hferraud          #+#    #+#             */
/*   Updated: 2022/08/21 23:34:11 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush.h"

void	free_nbr_list(struct s_int *head)
{
	struct s_int	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head->number);
		free(head);
		head = tmp;
	}
}

void	free_dict_list(t_dict *head)
{
	t_dict	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head->key);
		free(head->data);
		free(head);
		head = tmp;
	}
}
