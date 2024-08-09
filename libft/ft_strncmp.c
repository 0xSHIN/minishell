/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:00:36 by jmastora          #+#    #+#             */
/*   Updated: 2023/10/29 21:29:53 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*strg1;
	unsigned char	*strg2;
	size_t			i;

	i = 0;
	strg1 = ((unsigned char *)str1);
	strg2 = ((unsigned char *)str2);
	while ((i < n) && (strg1[i] || strg2[i]))
	{
		if (strg1[i] != strg2[i])
		{
			return (strg1[i] - strg2[i]);
		}
		i++;
	}
	return (0);
}
