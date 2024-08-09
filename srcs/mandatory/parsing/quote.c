/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 01:02:45 by jmastora          #+#    #+#             */
/*   Updated: 2023/11/06 06:51:20 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_put_neg(char *str)
{
	int		i;
	char	c;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == SQ || str[i] == DQ)
		{
			c = str[i];
			i++;
			while (str[i] && str[i] != c)
				str[i++] *= -1;
		}
		if (str[i])
			i++;
	}
	return (str);
}

char	*ft_put_pos(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		while (str[i] && (signed char)str[i] < 0)
		{
			str[i] *= -1;
			i++;
		}
		if (str[i])
			i++;
	}
	return (str);
}

int	ft_check_parenth(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '(')
		{
			while (str[i] && (str[i] == '(' || ft_isspace(str[i])))
				i++;
			if (str[i] == ')')
				return (1);
		}
		if (str[i])
			i++;
	}
	return (0);
}
