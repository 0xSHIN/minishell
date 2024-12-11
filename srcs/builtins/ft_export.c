/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:15:51 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/07 03:23:21 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_e;

void	create_var(t_pipex *pipex, char *var_name, char *key)
{
	int		i;
	int		j;
	char	**envp;
	char	*temp;
	int		p;

	i = 0;
	j = 0;
	while (pipex->envp[i])
		i++;
	envp = ft_calloc(sizeof(char *), (i + 2));
	while (j < i)
	{
		envp[j] = ft_strdup(pipex->envp[j]);
		j++;
	}
	temp = ft_strjoin(var_name, "=");
	envp[j] = ft_strjoin(temp, key);
	free(temp);
	p = 0;
	while (pipex->envp[p])
		free(pipex->envp[p++]);
	free(pipex->envp);
	pipex->envp = envp;
}

bool	is_valid_var_name(char *var_name)
{
	int	i;

	i = 1;
	if (!ft_isalpha(var_name[0]) && var_name[0] != '_')
	{
		g_e = 1;
		return (false);
	}
	while (var_name[i] != '=' && var_name[i] != '\0' && (var_name[i
				+ 1] != '"'))
	{
		if (!ft_isalnum(var_name[i]) && var_name[i] != '_')
		{
			g_e = 1;
			return (false);
		}
		i++;
	}
	return (true);
}

void	modify_var(t_pipex *pipex, char *var_name, char *key)
{
	char	*existing;
	int		i;
	int		index;
	char	*value;

	existing = find_env_var(pipex->envp, var_name);
	if (!existing)
		return ;
	value = ft_strjoin_egal(var_name, key);
	i = -1;
	index = -1;
	while (pipex->envp[++i])
	{
		if (pipex->envp[i] == existing)
		{
			index = i;
			break ;
		}
	}
	if (index != -1)
	{
		free(pipex->envp[index]);
		pipex->envp[index] = value;
	}
}

int	ft_export(t_pipex *pipex, char **arguments)
{
	char	*str;
	int		i;

	i = 0;
	if (!arguments[1])
		return (ft_env(pipex), 1);
	while (arguments[++i])
	{
		if (!is_valid_var_name(arguments[i]))
			return (ft_printf(2,
					"minishell: export: `%s': not a valid identifier\n",
					arguments[i]));
		else
		{
			str = ft_strchr(arguments[i], '=');
			if (!str)
				return (1);
			str[0] = '\0';
			if (!find_env_var(pipex->envp, arguments[i]))
				create_var(pipex, arguments[i], str + 1);
			else
				modify_var(pipex, arguments[i], str + 1);
		}
	}
	return (0);
}
