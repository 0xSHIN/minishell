/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:10:19 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/06 22:40:39 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	separator123(char *str)
{
	if ((*str == '|' && *(str + 1) == '|') || (*str == '&' && *(str
				+ 1) == '&'))
		return (2);
	if (*str == '|' || *str == '<' || *str == '>' || *str == '&' || *str == '$')
		return (1);
	return (0);
}

int	ft_spesize(char *s)
{
	int	i;
	int	len;
	int	flag;

	flag = 0;
	len = 1;
	i = 0;
	while (s[i])
	{
		if (separator123(s + i))
		{
			flag++;
			i += separator123(s + i);
			len++;
		}
		if (flag)
		{
			flag--;
			len++;
		}
		i++;
	}
	return (len);
}

void	fill_split(char **split, char *s, int *i_j_k_len)
{
	while (s[i_j_k_len[0]] && separator123(s + i_j_k_len[0]) < 2)
	{
		split[i_j_k_len[1]][i_j_k_len[2]] = s[i_j_k_len[0]];
		i_j_k_len[2]++;
		i_j_k_len[0]++;
	}
	i_j_k_len[2] = 0;
	i_j_k_len[1]++;
}

void	handle_separator(char **split, char *s, int *i_j_k_len)
{
	if (s[i_j_k_len[0]] && separator123(s + i_j_k_len[0]) < 2)
	{
		while (s[i_j_k_len[0] + i_j_k_len[3]] && separator123(s + i_j_k_len[0]
				+ i_j_k_len[3]) < 2)
			i_j_k_len[3]++;
		split[i_j_k_len[1]] = ft_calloc(sizeof(char), (i_j_k_len[3] + 1));
		if (!split[i_j_k_len[1]])
			return ;
		i_j_k_len[3] = 0;
		fill_split(split, s, i_j_k_len);
	}
	else if (s[i_j_k_len[0]] && separator123(s + i_j_k_len[0]) == 2)
	{
		split[i_j_k_len[1]] = ft_calloc(sizeof(char), 3);
		if (!split[i_j_k_len[1]])
			return ;
		while (s[i_j_k_len[0]] && separator123(s + i_j_k_len[0]))
		{
			split[i_j_k_len[1]][i_j_k_len[2]] = s[i_j_k_len[0]];
			i_j_k_len[2]++;
			i_j_k_len[0]++;
		}
		i_j_k_len[2] = 0;
		i_j_k_len[1]++;
	}
}

char	**ft_slip(char *s)
{
	char	**split;
	int		i_j_k_len[4];

	ft_memset(i_j_k_len, 0, sizeof(i_j_k_len));
	split = ft_calloc(sizeof(char *), (ft_spesize(s) + 1));
	if (!split)
		return (NULL);
	while (s[i_j_k_len[0]])
	{
		while (s[i_j_k_len[0]] == ' ' || s[i_j_k_len[0]] == '	')
			i_j_k_len[0]++;
		if (!s[i_j_k_len[0]])
			return (free(split), NULL);
		handle_separator(split, s, i_j_k_len);
		if (!split[i_j_k_len[1] - 1])
			return (NULL);
	}
	return (split);
}
