/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:40:14 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/07 02:52:02 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_e;

void	sig_int(int sig)
{
	if (sig == SIGINT)
	{
		ft_printf(1, "\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_e = 130;
	}
}

void	sig_quit(int sig)
{
	t_pipex	*pipex;

	pipex = starton();
	if (sig == SIGQUIT)
	{
		ft_printf(1, "\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		ft_tab_free(pipex->envp);
		g_e = 131;
		exit (131);
	}
}

void	sig_fork(int sig)
{
	if (sig == SIGQUIT)
		exit(131);
	if (sig == SIGINT)
		exit(130);
}
