/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:43:05 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/07 01:43:50 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_e;

int	check_direct_command(char *command)
{
	if (ft_strchr(command, '/') != NULL)
	{
		if (access(command, F_OK | X_OK) == 0)
			return (1);
		else
		{
			ft_printf(2, "minishell: %s: No such file or directory\n", command);
			g_e = 127;
			return (-1);
		}
	}
	return (0);
}

static int	get_pipe(t_here_doc *here, t_pipex *pipex, char *str)
{
	int	i;

	i = -1;
	while (++i < pipex->nb_here_doc)
	{
		if (!ft_strcmp(here[i].delimiters, str))
			return (here[i].pipe[0]);
	}
	return (-1);
}

void	redir_fd(t_cmd zebi, t_pipex *pipex)
{
	int	i;
	int	fd;

	i = -1;
	fd = -1;
	while (zebi.filename[++i])
	{
		if (zebi.type[i] == 1)
			fd = open(zebi.filename[i], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		else if (zebi.type[i] == 2)
			fd = open(zebi.filename[i], O_WRONLY | O_CREAT | O_APPEND, 0666);
		else if (zebi.type[i] == 3)
			fd = open(zebi.filename[i], O_RDONLY);
		else if (zebi.type[i] == 4)
			fd = get_pipe(pipex->here_doc, pipex, zebi.filename[i]);
		if (fd == -1)
			return (perror(zebi.filename[i]), free_child(zebi, pipex), exit(1));
		if (zebi.type[i] == 3 || zebi.type[i] == 4)
			dup2(fd, 0);
		else if (zebi.type[i] == 1 || zebi.type[i] == 2)
			dup2(fd, 1);
		close(fd);
	}
}

int	redir_fd_builtins(t_cmd zebi)
{
	int	i;
	int	fd;

	i = -1;
	fd = -1;
	while (zebi.filename[++i])
	{
		if (zebi.type[i] == 1)
			fd = open(zebi.filename[i], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		else if (zebi.type[i] == 2)
			fd = open(zebi.filename[i], O_WRONLY | O_CREAT | O_APPEND, 0666);
		else if (zebi.type[i] == 3)
			fd = open(zebi.filename[i], O_RDONLY);
		else if (zebi.type[i] == 4)
			fd = 0;
		if (fd == -1)
			return (perror(zebi.filename[i]), 1);
		if (zebi.type[i] == 1 || zebi.type[i] == 2)
			dup2(fd, 1);
		close(fd);
	}
	return (0);
}

void	redirect(t_pipex *pipex, int i)
{
	if (i != 0)
	{
		dup2(pipex->prev, 0);
		close(pipex->prev);
	}
	if (i != pipex->nbcmd - 1)
		dup2(pipex->fd[1], 1);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}
