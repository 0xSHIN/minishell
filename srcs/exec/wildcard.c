/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 08:23:19 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/06 06:44:57 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	matches(char *str, char *pattern)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && pattern[j])
	{
		if (pattern[j] == '*')
		{
			j++;
			if (pattern[j] == '\0')
				return (1);
			while (str[i] && !matches(&str[i], &pattern[j]))
				i++;
		}
		else if (str[i] == pattern[j++])
			i++;
		else
			return (0);
	}
	while (pattern[j] == '*')
		j++;
	return (str[i] == '\0' && pattern[j] == '\0');
}

char	*expand_wildcard_pattern(char *pattern)
{
	DIR				*open_dir;
	struct dirent	*dir;
	char			buffer[4096];
	size_t			buffer_pos;

	ft_memset(buffer, 0, sizeof(buffer));
	buffer_pos = 0;
	open_dir = opendir(".");
	if (!open_dir)
		return (free(pattern), NULL);
	dir = readdir(open_dir);
	while (dir && buffer_pos < sizeof(buffer) - 2)
	{
		if (ft_strcmp(dir->d_name, ".") && ft_strcmp(dir->d_name, "..")
			&& matches(dir->d_name, pattern)
			&& buffer_pos + ft_strlen(dir->d_name) + 1 < sizeof(buffer))
		{
			ft_strcat(buffer, dir->d_name);
			ft_strcat(buffer, " ");
			buffer_pos += ft_strlen(dir->d_name) + 1;
		}
		dir = readdir(open_dir);
	}
	closedir(open_dir);
	return (free(pattern), ft_strdup(buffer));
}

char	*expand_pattern_and_concat(char *result, char *expanded)
{
	char	*new_result;
	size_t	result_size;

	result_size = ft_strlen(result) + ft_strlen(expanded) + 1;
	new_result = ft_calloc(result_size + 1, 1);
	if (!new_result)
	{
		free(expanded);
		free(result);
		return (NULL);
	}
	ft_strcpy(new_result, result);
	ft_strcat(new_result, expanded);
	free(result);
	free(expanded);
	return (new_result);
}

char	*handle_wildcard(char *str, int *i, char *result, int *j)
{
	char	*wildcard_pattern;
	char	*expanded;
	int		pattern_start;
	int		s;
	int		size_expanded;

	s = ft_strlen(str);
	wildcard_pattern = ft_calloc((sizeof(char) * s + 1), 1);
	pattern_start = *i;
	while (str[*i] && str[*i] != ' ')
		(*i)++;
	ft_strlcpy(wildcard_pattern, &str[pattern_start], *i - pattern_start + 1);
	expanded = expand_wildcard_pattern(wildcard_pattern);
	if (expanded)
	{
		size_expanded = ft_strlen(expanded);
		result = expand_pattern_and_concat(result, expanded);
		(*j) += size_expanded;
	}
	return (result);
}

char	*expand_wildcard(char *str)
{
	char	*result;
	int		i;
	int		j;

	result = ft_calloc(ft_strlen(str) + 1, 150);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '*' && contains(str) != 2 && contains(str) != 1)
			result = handle_wildcard(str, &i, result, &j);
		else
			result[j++] = str[i++];
	}
	free(str);
	return (result);
}
