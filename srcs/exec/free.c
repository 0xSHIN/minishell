/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 02:54:22 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/06 04:09:10 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_bail(t_cmd bail)
{
	int	i;

	i = 0;
	while (bail.filename[i])
		free(bail.filename[i++]);
	free(bail.filename);
	i = 0;
	while (bail.cmd_arg[i])
		free(bail.cmd_arg[i++]);
	free(bail.cmd_arg);
	free(bail.type);
}

void	free_post_exec(t_pipex *pipex)
{
	free_heredoc(pipex);
	while (pipex->lst->prev)
		pipex->lst = pipex->lst->prev;
	clean_tree(&pipex->lst);
	ft_tab_free(pipex->tab);
	ft_tab_free(pipex->envp);
}

void	free_child(t_cmd bail, t_pipex *pipex)
{
	free_bail(bail);
	free_post_exec(pipex);
}
