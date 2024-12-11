/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:52:11 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/07 03:14:42 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_e;

int	run(t_pipex *pipex, char *str)
{
	char	**tab;
	t_lst	*lst;

	str = ft_parenth_check(str);
	tab = ft_put_in_tab(str);
	if (!tab)
		return (free(str), 0);
	lst = startast();
	lst = ft_init_tree(lst, tab);
	while (lst->prev)
		lst = lst->prev;
	free(str);
	execute_tree(lst, pipex);
	while (lst->prev)
		lst = lst->prev;
	clean_tree(&lst);
	return (0);
}

void	init_shell(t_pipex *pipex, char **envp)
{
	cpyenv(pipex, envp);
	signal(SIGINT, &sig_int);
	signal(SIGQUIT, SIG_IGN);
}

int	shell_loop(t_pipex *pipex)
{
	char	prompt[PATH_MAX];
	char	*str;

	str = NULL;
	while (1)
	{
		get_prompt(pipex, prompt);
		str = readline(prompt);
		if (!str)
			break ;
		if (!*str)
		{
			g_e = 0;
			continue ;
		}
		add_history(str);
		if (synt(str))
		{
			ft_print_error(synt(str));
			continue ;
		}
		else if (run(pipex, str))
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = starton();
	(void)argc;
	(void)argv;
	init_shell(pipex, envp);
	shell_loop(pipex);
	ft_tab_free(pipex->envp);
	return (0);
}
