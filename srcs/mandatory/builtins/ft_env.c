/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:16:07 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/01 22:33:07 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (!pipex || !pipex->envp)
		return ;
	while (pipex->envp[i])
		ft_printf(1, "%s\n", pipex->envp[i++]);
}
