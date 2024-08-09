/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmastora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:42:06 by jmastora          #+#    #+#             */
/*   Updated: 2023/05/24 20:35:15 by jmastora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	j;
	size_t	srclen;

	srclen = ft_strlen(src);
	if ((size == 0 && !dst) || (size == 0))
		return (srclen);
	dstlen = ft_strlen(dst);
	j = 0;
	if (dstlen > size)
		return (srclen + size);
	while (j + dstlen < size - 1 && src[j])
	{
		dst[dstlen + j] = src[j];
		j++;
	}
	dst[dstlen + j] = '\0';
		j++;
	return (dstlen + srclen);
}
