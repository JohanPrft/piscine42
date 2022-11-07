/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:42:17 by jprofit           #+#    #+#             */
/*   Updated: 2022/08/09 08:05:07 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_letter(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	ft_is_lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int	ft_is_uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

int	ft_is_alphanumeric(char c)
{
	if (ft_is_letter(c) || (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	if (ft_is_lowercase(str[0]))
		str[0] -= 32;
	i = 1;
	while (str[i])
	{
		if (ft_is_letter(str[i]) && !ft_is_alphanumeric(str[i - 1]))
		{
			if (ft_is_lowercase(str[i]))
				str[i] -= 32;
		}
		else if (ft_is_letter(str[i]) && ft_is_alphanumeric(str[i - 1]))
		{
			if (ft_is_uppercase(str[i]))
				str[i] += 32;
		}
		i++;
	}
	return (str);
}
