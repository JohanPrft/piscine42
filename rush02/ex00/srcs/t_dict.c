/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dict.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 10:40:51 by hferraud          #+#    #+#             */
/*   Updated: 2022/08/21 23:34:24 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush.h"

t_dict	*create_dict_elem(char *key, char *data)
{
	t_dict	*elem;

	elem = malloc(sizeof(t_dict));
	if (elem == NULL)
		return (NULL);
	elem->data = malloc(sizeof(data));
	if (elem->data == NULL)
		return (NULL);
	elem->key = key;
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

t_dict	*push_dict_elem(t_dict **head, char *key, char *data)
{
	t_dict	*elem;

	elem = create_dict_elem(key, data);
	elem->next = *head;
	*head = elem;
	return (elem);
}
