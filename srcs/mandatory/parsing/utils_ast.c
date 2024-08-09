/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:31:16 by jmastora          #+#    #+#             */
/*   Updated: 2023/11/06 06:50:31 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_tab_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_strtest(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '(' && str[i] == ')')
			i++;
		else if (str[i])
		{
			len++;
			i++;
		}
	}
	return (len);
}

char	*ft_parenth_check(char *str)
{
	int		i;
	int		j;
	char	*str2;
	int		len;

	i = 0;
	j = 0;
	len = ft_strtest(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
		return (NULL);
	while (str[i])
	{
		while (str[i] && (str[i] == ')' || str[i] == '('))
			i++;
		if (str[i])
		{
			str2[j] = str[i];
			j++;
			i++;
		}
	}
	str2[j] = '\0';
	return (str2);
}

char	**ft_put_in_tab(char *str)
{
	char	**tab;

	tab = ft_slip(str);
	if (!tab)
		return (NULL);
	return (tab);
}
