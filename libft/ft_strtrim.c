/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmastora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:02:01 by jmastora          #+#    #+#             */
/*   Updated: 2023/05/24 21:33:27 by jmastora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	ft_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	while (s1[i] && ft_set(((char *)s1)[i], set))
		i++;
	while (len > i && ft_set(((char *)s1)[len - 1], set))
		len--;
	str = ft_calloc(sizeof(char ), (len - i + 1));
	if (!(str))
		return (NULL);
	while (j + i < len)
	{
		str[j] = s1[i + j];
		j++;
	}
	return (str);
}
