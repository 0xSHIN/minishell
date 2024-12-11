/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_init_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 06:15:20 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/07 01:43:50 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_e;

void	initialize_execution(t_lst *lst, t_pipex *pipex, t_execution *exec_info)
{
	lst->cmd[0] = ft_put_pos(lst->cmd[0]);
	lst->cmd[0] = expand_wildcard(lst->cmd[0]);
	lst->cmd[0] = expand_env_var(pipex, lst->cmd[0]);
	lst->cmd[0] = ft_put_neg(lst->cmd[0]);
	here_doc(pipex, lst->cmd[0]);
	exec_info->cmd_count = 0;
	pipex->tab = ft_splitex(lst->cmd[0], "|", &exec_info->cmd_count);
	if (!pipex->tab)
		return ;
}

int	type_redirection(char *str)
{
	if (!ft_strcmp(str, ">"))
		return (1);
	if (!ft_strcmp(str, ">>"))
		return (2);
	if (!ft_strcmp(str, "<"))
		return (3);
	if (!ft_strcmp(str, "<<"))
		return (4);
	return (0);
}
