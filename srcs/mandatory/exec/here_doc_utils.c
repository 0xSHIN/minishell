/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:25:34 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/06 02:23:38 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_heredoc(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '<')
		{
			i++;
			if (str[i] == '<')
			{
				count++;
				i++;
			}
		}
		i++;
	}
	return (count);
}

void	*ft_free(void **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
	return (NULL);
}

void	free_heredoc(t_pipex *pipex)
{
	int	i;

	i = -1;
	if (!pipex->nb_here_doc)
		return ;
	while (++i < pipex->nb_here_doc)
		ft_free((void **)&pipex->here_doc[i].delimiters);
	ft_free((void **)&pipex->here_doc);
}

int	get_len_word(char *str)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	while (str[i] && !ft_isspace(str[i] && !ft_strchr("><|&", str[i])))
	{
		i++;
		r++;
	}
	return (r);
}

char	*get_word(char *str)
{
	int		i;
	int		r;
	char	*new;

	new = malloc(get_len_word(str) + 1);
	i = 0;
	r = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	while (str[i] && !ft_isspace(str[i]) && !ft_strchr("><|&", str[i]))
		new[r++] = str[i++];
	new[r] = 0;
	return (new);
}
