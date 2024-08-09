/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:27:03 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/07 02:24:16 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_e;

void	malloctout(char **tab, t_cmd *zebi)
{
	int	i;
	int	t;
	int	a;

	i = -1;
	t = 0;
	a = 0;
	while (tab[++i])
	{
		if (type_redirection(tab[i]))
			t++;
		else
			a++;
	}
	zebi->cmd_arg = ft_calloc(sizeof(char *), (a + 1));
	if (!zebi->cmd_arg)
		return (free_command(tab));
	zebi->filename = ft_calloc(sizeof(char *), (t + 1));
	if (!zebi->filename)
		return (free_command(tab));
	zebi->type = ft_calloc(sizeof(int), t);
	if (!zebi->type)
		return (free_command(tab));
}

static void	parse_redirection(char **tab, t_cmd *zebi, int *i, int *t)
{
	zebi->type[(*t)] = type_redirection(tab[*i]);
	(*i)++;
	if (tab[*i])
		zebi->filename[(*t)++] = ft_put_pos(ft_strdup(tab[*i]));
	else
		zebi->filename[(*t)++] = ft_put_pos(ft_strdup(""));
}

t_cmd	parsetout(char **tab)
{
	t_cmd	zebi;
	int		i;
	int		t;
	int		a;

	malloctout(tab, &zebi);
	i = -1;
	t = 0;
	a = 0;
	while (tab[++i])
	{
		if (type_redirection(tab[i]))
			parse_redirection(tab, &zebi, &i, &t);
		else
			zebi.cmd_arg[a++] = ft_put_pos(ft_strdup(tab[i]));
	}
	zebi.cmd_str = zebi.cmd_arg[0];
	return (zebi);
}

void	close_here_doc_pipe(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (++i < pipex->nb_here_doc)
		close(pipex->here_doc[i].pipe[0]);
}

void	*exec_pipe(t_pipex *pipex)
{
	int		i;
	t_cmd	cmd;

	i = -1;
	while (pipex->tab[++i])
	{
		pipex->tab[i] = ft_put_space(pipex->tab[i]);
		pipex->tab[i] = remove_quote(pipex->tab[i]);
	}
	i = -1;
	if (pipex->nbcmd == 1 && is_builtins(pipex->tab[0], &cmd))
		return (exec_builtins(pipex, &cmd), NULL);
	while (++i < pipex->nbcmd)
	{
		if (create_pipe(pipex) == -1)
			return (NULL);
		fork_and_exec(pipex, i);
	}
	close(pipex->fd[0]);
	wait_for_children(pipex);
	close_here_doc_pipe(pipex);
	free_heredoc(pipex);
	return (NULL);
}
