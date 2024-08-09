/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmastora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:47:31 by jmastora          #+#    #+#             */
/*   Updated: 2023/05/25 12:37:02 by jmastora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*sub;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (ft_strlen(s) < start)
		len = 0;
	else if (ft_strlen(s) < start + len)
		len = ft_strlen(s) - start;
	sub = ft_calloc(sizeof (char), len + 1);
	if (!(sub))
		return (NULL);
	while (i < len && s[start])
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}
