/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:15:40 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/07 01:43:50 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_e;

void	navigate_to_home(void)
{
	char	*home;

	home = getenv("HOME");
	if (home)
	{
		if (chdir(home) != 0)
		{
			perror("cd");
			g_e = 1;
		}
	}
	else
	{
		ft_printf(2, "cd: HOME environment variable not set\n");
		g_e = 1;
	}
}

void	handle_too_many_arguments(void)
{
	ft_printf(2, "bash: cd: too many arguments\n");
	g_e = 1;
}

void	change_to_directory(char *dir)
{
	if (chdir(dir) != 0)
	{
		perror(dir);
		g_e = 1;
	}
	else
		g_e = 0;
}

void	ft_cd(char **str)
{
	if (!str[1])
	{
		navigate_to_home();
		g_e = 1;
		return ;
	}
	if (str[1] && str[2])
	{
		handle_too_many_arguments();
		g_e = 1;
		return ;
	}
	change_to_directory(str[1]);
}
