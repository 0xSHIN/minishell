/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmastora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:01:43 by jmastora          #+#    #+#             */
/*   Updated: 2023/05/25 13:59:02 by jmastora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	char	*swap;
	char	*dswap;
	size_t	i;

	if (!destination && !source)
		return (NULL);
	i = 0;
	swap = (char *)source;
	dswap = (char *)destination;
	if (swap < dswap)
	{
		while (size-- > 0)
			dswap[size] = swap[size];
	}
	else
	{
		while (i < size)
		{
			dswap[i] = swap[i];
			i++;
		}
	}
	return (destination);
}
