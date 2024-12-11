/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 01:01:02 by jmastora          #+#    #+#             */
/*   Updated: 2023/11/06 06:49:28 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst	*ft_init_tree(t_lst *lst, char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (tab[i + 1] && ft_separator(tab[i + 1]) == 2)
		{
			if (lst->cmd)
			{
				lst->right = sep_nodetwo(lst, tab[++i]);
				lst = lst->right;
			}
			else if (!lst->cmd)
				lst = sep_node(lst, tab[++i]);
			lst->left = new_tree(lst, tab, i);
		}
	}
	if (!lst->prev && !lst->cmd)
		lst = new_node(tab);
	else
		lst->right = new_tree(lst, tab, i);
	if (!lst->cmd)
		return (NULL);
	ft_tab_free(tab);
	return (lst);
}

t_lst	*new_node(char **cmd)
{
	t_lst	*new;
	int		i;

	i = 0;
	new = NULL;
	new = (t_lst *)ft_calloc(sizeof(*new), 1);
	if (!new)
		return (NULL);
	new->check = 1;
	new->cmd = ft_calloc(sizeof(char *), (2));
	if (!new->cmd)
		return (NULL);
	while (cmd[i])
	{
		new->cmd[i] = ft_strdup(cmd[i]);
		i++;
	}
	return (new);
}

t_lst	*sep_nodetwo(t_lst *parent, char *cmd)
{
	t_lst	*new;

	new = (t_lst *)ft_calloc(sizeof(*new), 1);
	if (!new)
		return (NULL);
	new->prev = parent;
	new->check = 1;
	new->cmd = ft_calloc(sizeof(char *), 3);
	if (!new->cmd)
		return (NULL);
	new->cmd[0] = ft_strdup(cmd);
	return (new);
}

t_lst	*sep_node(t_lst *lst, char *cmd)
{
	t_lst	*new;

	new = (t_lst *)ft_calloc(sizeof(*new), 1);
	if (!new)
		return (NULL);
	new->check = 1;
	new->cmd = ft_calloc(sizeof(char *), 3);
	if (!new->cmd)
		return (NULL);
	new->cmd[0] = ft_strdup(cmd);
	if (lst)
		lst->right = new;
	return (new);
}

t_lst	*new_tree(t_lst *parent, char **cmd, int max)
{
	t_lst		*new;
	static int	i = 0;
	int			j;

	j = 0;
	new = (t_lst *)ft_calloc(sizeof(t_lst), 1);
	if (!new)
		return (NULL);
	new->check = 1;
	new->prev = parent;
	new->cmd = ft_calloc(sizeof(char *), (max - i) + 1);
	if (!new->cmd)
		return (NULL);
	while (i < max && ft_separator(cmd[i]) != 2)
		new->cmd[(j++)] = ft_strdup(cmd[(i++)]);
	while (cmd[i] && ft_separator(cmd[i]) == 2)
		i++;
	if (!cmd[i])
		i = 0;
	return (new);
}
