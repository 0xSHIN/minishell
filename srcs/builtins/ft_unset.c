/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:15:57 by alyildiz          #+#    #+#             */
/*   Updated: 2023/10/16 08:21:11 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_env_var(char **envp, const char *key)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], key, ft_strlen(key)) == 0)
			return (envp[i]);
	}
	return (NULL);
}

char	**remove_env_var(char **envp, const char *var)
{
	int		i;
	int		j;
	char	*existing;
	char	**new_envp;
	int		len;

	existing = find_env_var(envp, var);
	if (!existing)
		return (envp);
	len = 0;
	while (envp[len])
		len++;
	new_envp = ft_calloc(sizeof(char *), len);
	if (!new_envp)
		return (NULL);
	i = -1;
	j = 0;
	while (envp[++i])
	{
		if (envp[i] != existing)
			new_envp[j++] = ft_strdup(envp[i]);
		free(envp[i]);
	}
	free(envp);
	return (new_envp);
}

void	ft_unset(t_pipex *pipex, char **arguments)
{
	int	j;

	j = 1;
	while (arguments[j])
	{
		pipex->envp = remove_env_var(pipex->envp, arguments[j]);
		j++;
	}
}
