/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmastora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:22:43 by jmastora          #+#    #+#             */
/*   Updated: 2023/05/24 20:51:38 by jmastora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	int	i;

	i = ft_strlen(string);
	while (i >= 0)
	{
		if (string[i] == (char)searchedChar)
			return ((char *)string + i);
		i--;
	}
	return (0);
}
