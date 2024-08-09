/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 00:03:53 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/07 03:04:33 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_e;

void	handle_logical_operators(t_lst *lst, t_pipex *pipex)
{
	if (ft_strcmp(lst->cmd[0], "||") == 0)
	{
		execute_tree(lst->left, pipex);
		if (g_e != 0)
			execute_tree(lst->right, pipex);
	}
	else if (ft_strcmp(lst->cmd[0], "&&") == 0)
	{
		execute_tree(lst->left, pipex);
		if (g_e == 0)
			execute_tree(lst->right, pipex);
	}
}

void	execute_tree(t_lst *lst, t_pipex *pipex)
{
	t_execution	exec_info;

	if (!lst || is_separator(lst->cmd[0]))
		return (handle_logical_operators(lst, pipex));
	pipex->lst = lst;
	initialize_execution(lst, pipex, &exec_info);
	handle_execution(pipex, &exec_info.cmd_count);
}

void	handle_execution(t_pipex *pipex, int *cmd_index)
{
	if (*cmd_index > 0)
	{
		pipex->nbcmd = *cmd_index;
		exec_pipe(pipex);
	}
	ft_tab_free(pipex->tab);
}

void	free_command(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
