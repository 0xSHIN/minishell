/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:35:11 by jmastora          #+#    #+#             */
/*   Updated: 2023/10/20 09:59:43 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	f(unsigned int i, char c)
{
	char	str;

	str = c + ((char)i);
	return (str);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		size;
	int		i;
	char	*c;

	if (s == 0 || f == 0)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	c = ft_calloc(sizeof (char), size + 1);
	if (!(c))
		return (NULL);
	while (s[i] != '\0')
	{
		c[i] = f(i, s[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}
