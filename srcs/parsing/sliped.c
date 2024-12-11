/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sliped.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:57:21 by jmastora          #+#    #+#             */
/*   Updated: 2023/10/20 10:01:03 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// split pour faire un tab de commande et arguments

int	count_sliped(char **str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] && ft_isseparator(str[i][0]))
		i++;
	while (str[i] && !ft_isseparator(str[i][0]))
	{
		count++;
		i++;
	}
	return (count);
}

char	**ft_sliped(char **str)
{
	char	**str2;
	int		i;
	int		j;

	str2 = ft_calloc(sizeof(char *), (count_sliped(str) + 1));
	if (!str2)
		return (NULL);
	j = 0;
	i = 0;
	while (str[i])
	{
		while (str[i][0] == '-')
		{
			ft_memcpy(str2[j], str[i], ft_strlen(str[i]) + 1);
			i++;
			j++;
		}
		if (j != 0)
			return (str2);
		i++;
	}
	return (NULL);
}
