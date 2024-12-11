/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_sup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 06:50:03 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/07 02:49:59 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_e;

void	parent_process(t_pipex *pipex, int i)
{
	close(pipex->fd[1]);
	if (i)
		close(pipex->prev);
	pipex->prev = pipex->fd[0];
	signal(SIGQUIT, SIG_IGN);
}

int	create_pipe(t_pipex *pipex)
{
	if ((pipe(pipex->fd)) == -1)
	{
		perror("Error");
		return (-1);
	}
	return (0);
}

void	fork_and_exec(t_pipex *pipex, int i)
{
	signal(SIGINT, SIG_IGN);
	pipex->pid[i] = fork();
	if (pipex->pid[i] == -1)
	{
		perror("Error");
		ft_tab_free(pipex->tab);
		exit(1);
	}
	if (pipex->pid[i] == 0)
		child_process(pipex, i);
	else
		parent_process(pipex, i);
}

void	wait_for_children(t_pipex *pipex)
{
	int	i;
	int	segfaulted;

	i = 0;
	segfaulted = 0;
	while (i < pipex->nbcmd)
	{
		waitpid(pipex->pid[i++], &g_e, 0);
		if (WIFEXITED(g_e))
			g_e = WEXITSTATUS(g_e);
		if (g_e == 131 && !segfaulted++)
			ft_printf(2, "Quit (core dumped)\n");
	}
	signal(SIGINT, &sig_int);
}

void	child_process(t_pipex *pipex, int i)
{
	char	**cmd;
	char	*path;
	t_cmd	bail;

	signal(SIGINT, &sig_int);
	signal(SIGQUIT, &sig_fork);
	cmd = ft_split(pipex->tab[i], ' ');
	if (!cmd)
		return ;
	bail = parsetout(cmd);
	ft_tab_free(cmd);
	redirect(pipex, i);
	redir_fd(bail, pipex);
	if (!bail.cmd_str)
		return (free_child(bail, pipex), exit(g_e));
	if (is_builtin(bail.cmd_str))
		return (exec_builtin(&bail, pipex), free_child(bail, pipex),
			exit(g_e));
	path = get_path(pipex->envp, bail.cmd_str);
	if (path)
		execve(path, bail.cmd_arg, pipex->envp);
	if (errno == 13 || errno == 21)
		g_e = 126;
	return (free(path), free_child(bail, pipex), exit(g_e));
}
