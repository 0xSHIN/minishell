/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:16:04 by jmastora          #+#    #+#             */
/*   Updated: 2023/10/31 00:34:42 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbw(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{	
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (word);
}

char	**ft_frft(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

static char	*ft_cpy(char *split, const char *s, int start, int j)
{
	int	wsize;
	int	i;

	i = 0;
	wsize = j - start;
	split = ft_calloc(sizeof (char), wsize +1);
	if (!(split))
		return (NULL);
	while (i < (wsize))
	{
		split[i] = (char)s[i + start];
		i++;
	}
	split[i] = '\0';
	return (split);
}

static int	ft_init(int *i, int *j, char const *s, char c)
{
	*i = -1;
	*j = 0;
	return (ft_nbw(s, c));
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		size;
	int		i;
	int		start;
	int		j;

	if (!s)
		return (0);
	size = ft_init(&i, &j, s, c);
	split = ft_calloc(sizeof(char *), (size + 1));
	if (!(split))
		return (NULL);
	while (s[j] && ++i < size)
	{
		while ((s[j] == c) && s[j])
			j++;
		start = j;
		while ((s[j] != c) && s[j])
			j++;
		split[i] = ft_cpy(split[i], s, start, j);
		if (!(split[i]))
			return (ft_frft(split));
	}
	split[size] = 0;
	return (split);
}
