/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 00:15:27 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/06 06:47:39 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cpyenv(t_pipex *pipex, char **envp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (envp && envp[j])
		j++;
	pipex->envp = ft_calloc(sizeof(char *), (j + 1));
	if (!pipex->envp)
		return ;
	while (envp && envp[i])
	{
		pipex->envp[i] = ft_strdup(envp[i]);
		i++;
	}
}

char	*get_env_var_value(t_pipex *pipex, char *key)
{
	int		i;
	char	*to_copy;

	i = 0;
	while (pipex->envp[i])
	{
		if (ft_strncmp(pipex->envp[i], key, ft_strlen(key)) == 0
			&& pipex->envp[i][ft_strlen(key)] == '=')
		{
			to_copy = ft_strchr(pipex->envp[i], '=');
			return (to_copy + 1);
		}
		i++;
	}
	return (NULL);
}

char	*expand_var(t_pipex *pipex, t_expansion *exp)
{
	int		start;
	char	key[256];
	char	*value;

	value = NULL;
	start = exp->i;
	while (exp->str && exp->str[exp->i] && is_valid_char(exp->str[exp->i]))
		(exp->i)++;
	ft_strlcpy(key, &exp->str[start], exp->i - start + 1);
	value = get_env_var_value(pipex, key);
	if (value)
		return (value);
	else
		return (free(value), "");
}

char	*remove_quote(char *str)
{
	int		len;
	char	*str2;
	int		i;
	int		j;

	j = 0;
	i = 0;
	len = ft_strlen(str);
	str2 = ft_calloc(sizeof(char), len + 1);
	while (str[i])
	{
		if (str[i] == SQ || str[i] == DQ)
			i++;
		else
			str2[j++] = str[i++];
	}
	free(str);
	return (str2);
}
