/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:14:55 by jmastora          #+#    #+#             */
/*   Updated: 2023/10/20 10:01:31 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gn_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != c)
		i++;
	if (str[i] != c)
		return (NULL);
	return (str + i);
}

int	gn_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*gn_strjoin(char *str, char *buf, int r)
{
	char	*joined;
	int		len;

	len = gn_strlen(str);
	joined = malloc(len + r + 1);
	if (!joined)
		return (NULL);
	if (str)
		gn_strcpy (joined, str);
	gn_strdel (&str);
	gn_strcpy (joined + len, buf);
	return (joined);
}

char	*gn_strcpy(char *dest, char	*src)
{
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}

char	*gn_strdup(char *src)
{
	int		i;
	char	*dest;

	i = gn_strlen(src);
	dest = malloc(i + 1);
	if (!dest)
		return (NULL);
	gn_strcpy(dest, src);
	return (dest);
}
