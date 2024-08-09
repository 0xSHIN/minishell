/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:41:16 by jmastora          #+#    #+#             */
/*   Updated: 2023/11/01 18:57:37 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	int		size;
	int		i;
	char	*dup;

	size = ft_strlen(source);
	i = 0;
	dup = ft_calloc(sizeof (char), size + 1);
	if (!(dup))
	{
		return (NULL);
	}
	while (source[i] != '\0')
	{
		dup[i] = source[i];
		i++;
	}
	return (dup);
}
