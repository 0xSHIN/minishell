/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 06:13:16 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/07 01:43:50 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_e;

int	is_separator(char *str)
{
	if (!str)
		return (0);
	if (ft_strcmp(str, "||") == 0 || ft_strcmp(str, "&&") == 0)
		return (1);
	return (0);
}

void	clean_tree(t_lst **lst)
{
	int	i;

	i = 0;
	if (!(*lst))
		return ;
	if ((*lst)->left)
		clean_tree(&((*lst)->left));
	if ((*lst)->right)
		clean_tree(&((*lst)->right));
	if ((*lst)->cmd)
	{
		while ((*lst)->cmd[i])
		{
			free((*lst)->cmd[i]);
			i++;
		}
		free((*lst)->cmd);
	}
	if ((*lst)->check == 1)
	{
		free(*lst);
	}
}

int	ft_spacelen(char *str)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (ft_separator(&str[i]) || ft_isparenth(str[i]))
			len++;
		i++;
	}
	return (len * 2);
}

char	*ft_put_space(char *str)
{
	int		i;
	int		j;
	char	*str2;

	j = 0;
	i = -1;
	str2 = ft_calloc(sizeof(char), (ft_strlen(str) + ft_spacelen(str) + 1));
	if (!str2)
		return (NULL);
	while (str[++i])
	{
		if (ft_separator(&str[i]) || ft_isparenth(str[i]))
		{
			str2[i + (j++)] = ' ';
			while (str[i] && (ft_separator(&str[i]) || ft_isparenth(str[i])))
			{
				str2[i + j] = str[i];
				i++;
			}
			str2[i + (j++)] = ' ';
		}
		str2[i + j] = str[i];
	}
	free(str);
	return (str2);
}
