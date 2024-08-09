/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmastora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:00:46 by jmastora          #+#    #+#             */
/*   Updated: 2023/05/24 20:57:15 by jmastora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	if (!s1 && n == 0)
		return (NULL);
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	while (i < n && s1[i] != '\0')
	{
		y = 0;
		while (s1[i + y] && s1[i + y] == s2[y] && i + y < n)
		{
			y++;
		}
		if (s2[y] == '\0')
		{
			return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
