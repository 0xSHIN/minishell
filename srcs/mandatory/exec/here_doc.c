/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 01:18:51 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/07 02:38:55 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_getdelims(char *str, t_here_doc *here_doc)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '<')
		{
			i++;
			if (str[i] == '<')
			{
				i++;
				here_doc[count].delimiters = get_word(&str[i]);
				pipe(here_doc[count++].pipe);
			}
		}
		i++;
	}
}

static char	*openfileshd(int index, t_here_doc *here)
{
	char	*s;
	char	*prompt;

	prompt = "> ";
	while (1)
	{
		s = readline(prompt);
		if (!s || !ft_strcmp(s, here[index].delimiters))
			break ;
		ft_putendl_fd(s, here[index].pipe[1]);
		free(s);
	}
	close(here[index].pipe[1]);
	close(here[index].pipe[0]);
	return (NULL);
}

static void	exit_hd(int sig)
{
	t_pipex	*pipex;
	int		i;

	pipex = starton();
	if (sig == SIGINT)
	{
		ft_printf(2, "\n");
		i = -1;
		while (++i < pipex->nb_here_doc)
		{
			close(pipex->here_doc[i].pipe[1]);
			close(pipex->here_doc[i].pipe[0]);
			if (pipex->here_doc[i].delimiters != NULL)
				ft_free((void **)&pipex->here_doc[i].delimiters);
		}
		ft_tab_free(pipex->tab);
		exit(130);
	}
}

static void	child_hd(t_pipex *pipex, char *str)
{
	int	i;

	(void)str;
	signal(SIGINT, &exit_hd);
	i = -1;
	while (++i < pipex->nb_here_doc)
		openfileshd(i, pipex->here_doc);
	free_heredoc(pipex);
	clean_tree(&pipex->lst);
	ft_tab_free(pipex->envp);
	exit(1);
}

t_here_doc	*here_doc(t_pipex *pipex, char *str)
{
	t_here_doc	*hered;
	int			i;
	pid_t		pid;

	hered = NULL;
	pipex->nb_here_doc = count_heredoc(str);
	if (!pipex->nb_here_doc)
		return (NULL);
	pipex->here_doc = ft_calloc(sizeof(t_here_doc), pipex->nb_here_doc);
	ft_getdelims(str, pipex->here_doc);
	signal(SIGINT, SIG_IGN);
	pid = fork();
	i = -1;
	if (pid == 0)
		child_hd(pipex, str);
	else if (pid > 0)
	{
		while (++i < pipex->nb_here_doc)
			close(pipex->here_doc[i].pipe[1]);
	}
	signal(SIGINT, &sig_int);
	waitpid(pid, NULL, 0);
	return (hered);
}
