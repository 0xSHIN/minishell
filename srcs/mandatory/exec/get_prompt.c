/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:28:31 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/06 02:25:17 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int	count;
	int	size_dest;

	count = 0;
	size_dest = -1;
	while (dest[++size_dest] != '\0')
		;
	while (src[count] != '\0')
	{
		dest[(size_dest + count)] = src[count];
		count++;
	}
	dest[(size_dest + count)] = '\0';
	return (dest);
}

char	*get_user(t_pipex *pipex)
{
	int		i;
	char	*user;

	i = 0;
	user = "guest";
	while (pipex->envp[i])
	{
		if (ft_strncmp(pipex->envp[i], "USER", 4) == 0)
			user = pipex->envp[i] + 5;
		i++;
	}
	return (user);
}

char	*get_current_path(void)
{
	char	*home;
	char	*current_path;
	char	*relative_path;

	home = getenv("HOME");
	current_path = getcwd(NULL, PATH_MAX);
	relative_path = NULL;
	if (!home || !current_path)
		return (current_path);
	if (ft_strncmp(home, current_path, ft_strlen(home)) == 0)
	{
		relative_path = ft_calloc(ft_strlen(current_path) - ft_strlen(home) + 2,
				1);
		if (!relative_path)
			return (free(current_path), NULL);
		ft_strlcpy(relative_path, "~", 1);
		ft_strlcat(relative_path, current_path + ft_strlen(home),
			ft_strlen(current_path));
		free(current_path);
		return (relative_path);
	}
	return (current_path);
}

char	*get_prompt(t_pipex *pipex, char *prompt)
{
	char	*user;
	char	*path;

	path = get_current_path();
	if (!path || path[0] == '\0')
		return (ft_strcpy(prompt, ">"), prompt);
	user = get_user(pipex);
	if (!user)
		return (ft_strcpy(prompt, ">"), prompt);
	ft_strcpy(prompt, BLUE);
	ft_strcat(prompt, user);
	ft_strcat(prompt, "@minishell");
	ft_strcat(prompt, RED " ~ " GREEN);
	ft_strcat(prompt, path);
	free(path);
	ft_strcat(prompt, " $ " DEFAULT);
	return (prompt);
}
