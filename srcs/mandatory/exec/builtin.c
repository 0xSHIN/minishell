/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:25:05 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/07 03:10:26 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_e;

int	is_builtins(char *str, t_cmd *cmd)
{
	char		**split_str;
	static char	*builtins[7] = {"echo", "cd", "pwd", "env",
		"export", "unset", "exit"};
	int			i;
	int			result;

	i = 0;
	result = 0;
	if (!str || !*str)
		return (0);
	split_str = ft_split(str, ' ');
	if (!split_str || !split_str[0])
		return (0);
	*cmd = parsetout(split_str);
	while (i < 7)
	{
		if (!ft_strcmp(split_str[0], builtins[i]))
			result = 1;
		i++;
	}
	free_command(split_str);
	if (result == 0)
		free_bail(*cmd);
	return (result);
}

int	is_builtin(char *str)
{
	char		**split_str;
	static char	*builtins[7] = {"echo", "cd", "pwd", "env",
		"export", "unset", "exit"};
	int			result;
	int			i;

	result = 0;
	i = 0;
	if (!str)
		return (0);
	split_str = ft_split(str, ' ');
	if (!split_str)
		return (0);
	if (!*split_str)
		return (ft_tab_free(split_str), 0);
	while (i < 7)
	{
		if (!ft_strcmp(split_str[0], builtins[i]))
			result = 1;
		i++;
	}
	ft_tab_free(split_str);
	return (result);
}

char	**copy_tmp(t_cmd *cmd)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = ft_calloc(sizeof(char *), ft_strlen(*cmd->cmd_arg) + 1);
	while (cmd->cmd_arg[++i])
		tmp[i] = ft_strdup(cmd->cmd_arg[i]);
	return (tmp);
}

int	exec_builtin(t_cmd *bail, t_pipex *pipex)
{
	char	**tmp;

	if (ft_strcmp(bail->cmd_str, "echo") == 0)
		ft_echo(bail->cmd_arg);
	else if (ft_strcmp(bail->cmd_str, "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(bail->cmd_str, "env") == 0)
		ft_env(pipex);
	else if (ft_strcmp(bail->cmd_str, "export") == 0)
		ft_export(pipex, bail->cmd_arg);
	else if (ft_strcmp(bail->cmd_str, "unset") == 0)
		ft_unset(pipex, bail->cmd_arg);
	else if (ft_strcmp(bail->cmd_str, "cd") == 0)
		ft_cd(bail->cmd_arg);
	else if (ft_strcmp(bail->cmd_str, "exit") == 0)
		return (tmp = copy_tmp(bail), free_bail(*bail),
			free_post_exec(pipex), ft_exit(tmp), 1);
	return (1);
}

int	exec_builtins(t_pipex *pipex, t_cmd *cmd)
{
	int		std;
	int		red;
	char	**tmp;

	std = dup(1);
	red = redir_fd_builtins(*cmd);
	if (red == 1)
		return (g_e = 1, dup2(std, 1), close(std), free_bail(*cmd), 1);
	if (ft_strcmp(cmd->cmd_str, "echo") == 0)
		ft_echo(cmd->cmd_arg);
	else if (ft_strcmp(cmd->cmd_str, "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(cmd->cmd_str, "env") == 0)
		ft_env(pipex);
	else if (ft_strcmp(cmd->cmd_str, "export") == 0)
		ft_export(pipex, cmd->cmd_arg);
	else if (ft_strcmp(cmd->cmd_str, "unset") == 0)
		ft_unset(pipex, cmd->cmd_arg);
	else if (ft_strcmp(cmd->cmd_str, "cd") == 0)
		ft_cd(cmd->cmd_arg);
	else if (ft_strcmp(cmd->cmd_str, "exit") == 0)
		return (tmp = copy_tmp(cmd), free_bail(*cmd), dup2(std, 1), close(std),
			free_post_exec(pipex), ft_exit(tmp), 1);
	return (dup2(std, 1), close(std), free_bail(*cmd), 1);
}
