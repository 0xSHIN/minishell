/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:15:18 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/07 01:43:50 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_e;

bool	ft_check_n(char *str)
{
	int		i;
	bool	only_n;

	i = 0;
	only_n = true;
	if (str[i] == '-')
	{
		i++;
		while (str[i])
		{
			if (str[i] != 'n')
				only_n = false;
			i++;
		}
	}
	return (only_n);
}

int	contains(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == SQ)
			return (1);
		if (str[i] == DQ)
			return (2);
		i++;
	}
	return (0);
}

void	ft_echo(char **args)
{
	bool	newline;
	int		i;
	int		args_count;

	args_count = -1;
	newline = true;
	i = 1;
	while (args[++args_count])
		args[args_count] = ft_put_pos(args[args_count]);
	if (args_count >= 2 && ft_strncmp(args[1], "-n", 2) == 0
		&& ft_check_n(args[1]))
	{
		i = 2;
		newline = false;
	}
	while (i != args_count)
	{
		if (i == args_count - 1)
			ft_printf(1, "%s", args[i++]);
		else
			ft_printf(1, "%s ", args[i++]);
		g_e = 0;
	}
	if (newline)
		ft_printf(1, "\n");
}
