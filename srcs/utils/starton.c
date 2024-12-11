/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starton.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmastora <jmastora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:16:57 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/05 03:08:57 by jmastora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_args	*starton_args(void)
{
	static t_args	args;

	return (&args);
}

t_minishell	*starton_shell(void)
{
	static t_minishell	shell;

	return (&shell);
}

t_lst	*startast(void)
{
	static t_lst	lst;

	return (&lst);
}

t_pipex	*starton(void)
{
	static t_pipex	pipex;

	return (&pipex);
}

t_here_doc	*starton_here_doc(void)
{
	static t_here_doc	here_doc;

	return (&here_doc);
}
