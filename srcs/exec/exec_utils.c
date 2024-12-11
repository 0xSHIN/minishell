/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 03:32:10 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/07 01:43:50 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_e;

char	*get_path(char **env, char *command)
{
	char	**tab;
	int		j;
	char	*tmp2;
	int		direct_check;

	j = -1;
	direct_check = check_direct_command(command);
	if (direct_check == 1)
		return (ft_strdup(command));
	else if (direct_check == -1)
		return (NULL);
	tab = get_true_path(env);
	if (!tab)
		return (ft_printf(2, "minishell: %s command not found\n", command),
			g_e = 127, NULL);
	while (tab[++j])
	{
		tmp2 = ft_strjoin_slash(tab[j], command);
		if (access(tmp2, F_OK | X_OK) == 0)
			return (free_command(tab), tmp2);
		free(tmp2);
	}
	ft_printf(2, "minishell: %s: command not found\n", command);
	return (g_e = 127, free_command(tab), NULL);
}

char	**get_true_path(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (ft_split(env[i] + 5, ':'));
		i++;
	}
	return (NULL);
}
