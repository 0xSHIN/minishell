/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:37:33 by jmastora          #+#    #+#             */
/*   Updated: 2023/10/26 04:44:17 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	if (!s1[i] && !s2[i])
		return (0);
	return (1);
}

char	*ft_strjoin_egal(char *s1, char *s2)
{
	int		i;
	int		len;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	str = ft_calloc(sizeof(char), (len + 2));
	if (!(str))
		return (NULL);
	i = 0;
	while (*s1)
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	str[i++] = '=';
	while (*s2)
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	return (str);
}

char	*ft_strjoin_slash(char *s1, char *s2)
{
	int		i;
	int		len;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	str = ft_calloc(sizeof(char), (len + 2));
	if (!(str))
		return (NULL);
	i = 0;
	while (*s1)
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	str[i++] = '/';
	while (*s2)
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	return (str);
}

char	*ft_strjoin_space(char *s1, char *s2)
{
	int		i;
	int		len;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	str = ft_calloc(sizeof(char), (len + 2));
	if (!(str))
		return (NULL);
	i = 0;
	while (*s1)
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	str[i++] = ' ';
	while (*s2)
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	return (str);
}
