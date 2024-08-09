/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmastora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:54:08 by jmastora          #+#    #+#             */
/*   Updated: 2023/05/24 20:02:32 by jmastora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = ((unsigned char *)s);
	while (i < size)
	{
		if ((str[i]) == ((unsigned char)c))
		{
			return (str + i);
		}
		i++;
	}
	return (NULL);
}
