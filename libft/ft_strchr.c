/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmastora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 19:09:02 by jmastora          #+#    #+#             */
/*   Updated: 2023/05/24 20:54:19 by jmastora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr( const char *string, int searchedChar)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(string);
	while (i < size)
	{
		if (string[i] == (char)searchedChar)
			return ((char *)string + i);
		i++;
	}
	if (string[i] == (char)searchedChar)
		return ((char *)string + i);
	return (NULL);
}
