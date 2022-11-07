/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 09:00:01 by jprofit           #+#    #+#             */
/*   Updated: 2022/08/09 08:41:26 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	*ptrs;
	int	*ptre;
	int	temp;

	i = 0;
	ptrs = &tab[0];
	ptre = &tab[9];
	while (i < ((size - 1) / 2))
	{
		temp = *ptrs;
		*ptrs = *ptre;
		*ptre = temp;
		ptrs++;
		ptre--;
		i++;
	}
}
