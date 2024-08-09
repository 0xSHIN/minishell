/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:39:11 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/02 21:13:50 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	freeloop(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_countdelim(char const *str, char *charset)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str && str[i])
	{
		while (str[i] && ft_strchr(charset, str[i]))
			i++;
		if (str[i] == '\0')
			break ;
		counter++;
		while (str[i] && !ft_strchr(charset, str[i]))
			i++;
	}
	return (counter);
}

char	*ft_strtsub(char const *str, int start, int end)
{
	int		i;
	char	*var;

	i = 0;
	var = ft_calloc(sizeof(char), end - start + 1);
	if (!var)
		return (NULL);
	while (((start + i) < end) && str[i])
	{
		var[i] = str[start + i];
		i++;
	}
	var[i] = '\0';
	return (var);
}

char	**to_tab(char **tab, char const *s, char *charset, int count)
{
	int	i;
	int	index;
	int	start;

	i = 0;
	index = 0;
	while (index < count)
	{
		while (s[i] && ft_strchr(charset, s[i]))
			i++;
		start = i;
		while (s[i] && (!ft_strchr(charset, s[i])))
			i++;
		tab[index] = ft_strtsub(s, start, i);
		if (!tab[index])
		{
			freeloop(tab);
			return (NULL);
		}
		index++;
	}
	return (tab);
}

char	**ft_splitex(char *str, char *charset, int *size)
{
	char	**tab;

	if (!str || !*str)
		return (ft_calloc(sizeof(char *) * 1, 1));
	*size = ft_countdelim(str, charset);
	tab = ft_calloc(sizeof(char *) * (*size + 1), 1);
	if (!tab)
		return (NULL);
	tab = to_tab(tab, str, charset, *size);
	return (tab);
}
