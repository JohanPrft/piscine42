/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:43:00 by dbiguene          #+#    #+#             */
/*   Updated: 2022/08/21 23:34:22 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush.h"

/* ************************************************************************** */
/*																			  */
/* 	push:   Adds element to linked list										  */
/*																			  */
/*	Adds it to last position											 	  */
/*																			  */
/*	Last element pushed is pointed by "next" key of your previous last one	  */
/*																			  */
/*	First element has to be defined manually,								  */
/*		if impossible set it to -1 and push will re-assign					  */
/*																			  */
/* ************************************************************************** */

void	push(struct s_int *head, char *n)
{
	struct s_int	*current;

	current = head;
	if (current->number[0] == '\0')
	{
		current->number = n;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = (struct s_int *) malloc(sizeof(struct s_int));
	if (current->next)
	{
		current->next->number = n;
		current->next->next = NULL;
	}
}

/* ************************************************************************** */
/*																			  */
/* 	first_parse:   Returns int by hundred packets							  */
/*																			  */
/*	e.g: 2147 => {0, 0, 2, 147}											 	  */
/*																			  */
/*	First element of array is billions, second is for millions				  */
/*																			  */
/*	Third is for thousands, and fourth is for digits						  */
/*																			  */
/* ************************************************************************** */

int	*first_parse(char *nbr)
{
	int	*tab;
	int	len;
	int	i;
	int	j;

	len = ft_strlen(nbr);
	tab = malloc(sizeof(int) * ((len - 1) + (3 - (len - 1) % 3)) / 3);
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = len - 1;
	while (i < ((len - 1) + (3 - (len - 1) % 3)) / 3)
		tab[i++] = 0;
	i = (((len - 1) + (3 - (len - 1) % 3)) / 3) - 1;
	while (j - 2 >= 0)
	{
		tab[i] = ((nbr[j - 2] - 48) * 100) + ((nbr[j - 1] - 48) * 10);
		tab[i--] += (nbr[j] - 48);
		j -= 3;
	}
	if (j == 0)
		tab[i] = nbr[0] - 48;
	else if (j == 1)
		tab[i] = (nbr[0] - 48) * 10 + nbr[1] - 48;
	return (tab);
}

/* ************************************************************************** */
/*																			  */
/* 	add_number:   Factorizes and adds a 3 digits number to linked list		  */
/*																			  */
/*	e.g: 451 => 400, 50, 1												 	  */
/*																			  */
/*	Requires "push" function												  */
/*																			  */
/*	Number you'll add has to respect "first_parse" format					  */
/*																			  */
/* ************************************************************************** */

void	add_number(struct s_int *head, int n)
{
	if (n >= 100)
	{
		push(head, ft_pos_itoa(n / 100));
		push(head, "100");
	}
	if (n % 100 >= 10)
	{
		if (n % 100 >= 20)
			push(head, ft_pos_itoa(((n % 100) / 10) * 10));
		else
		{
			push(head, ft_pos_itoa(n % 100));
			return ;
		}
	}
	if (n % 10)
		push(head, ft_pos_itoa(n % 10));
}

/* ************************************************************************** */
/*																			  */
/* 	add_elem:   Adds a 3 digits number to linked list						  */
/*																			  */
/*	Requires "push", "ft_strlen" and "add_number" functions					  */
/*																			  */
/*	Number you'll add has to respect "first_parse" format					  */
/*																			  */
/* ************************************************************************** */

void	add_elem(int *tab, struct s_int *head, char *x, int i)
{
	if (tab[i] != 0)
	{
		add_number(head, tab[i++]);
		if (ft_strlen(x) >= 4)
			push(head, x);
	}
}

/* ************************************************************************** */
/*																			  */
/* 	parse_int:   Returns given number, factorized, each factor is an 		  */
/*				 element of the returned linked list		 				  */
/*																			  */
/*	e.g: 2354 => 2, 1000, 3, 100, 50, 4									 	  */
/*																			  */
/*	Requires "first_parse", "push" and "add_number" functions				  */
/*																			  */
/*	Number you'll add has to respect "first_parse" format					  */
/*																			  */
/* ************************************************************************** */

struct s_int	*parse_int(char *nbr)
{
	int				i;
	int				len;
	int				*tab;
	char			*x;
	struct s_int	*head;

	i = 0;
	tab = first_parse(nbr);
	if (tab == NULL)
		return (NULL);
	len = ft_strlen(nbr);
	x = ft_ten_power((len - 1) + (3 - (len - 1) % 3) - 3);
	head = (struct s_int *) malloc(sizeof(struct s_int));
	if (head == NULL)
		return (NULL);
	head->number = "\0";
	head->next = NULL;
	while (i < ((len - 1) + (3 - (len - 1) % 3)) / 3)
	{
		add_elem(tab, head, x, i++);
		x = ft_ten_power((len - 1) + (3 - (len - 1) % 3) - 3 * (i + 1));
	}
	return (head);
}
