/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:33:37 by jmastora          #+#    #+#             */
/*   Updated: 2023/09/24 11:26:19 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*ptr;
	size_t	i;
	size_t	total;

	total = elementCount * elementSize;
	if (elementCount != 0 && total / elementCount != elementSize)
		return (NULL);
	i = 0;
	ptr = malloc(elementCount * elementSize);
	if (!(ptr))
		return (NULL);
	while (i < (elementCount * elementSize))
	{
		(((unsigned char *)ptr)[i]) = '\0';
		i++;
	}
	return (ptr);
}
