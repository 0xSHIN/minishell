/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmastora <jmastora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:15:42 by alyildiz          #+#    #+#             */
/*   Updated: 2023/10/15 02:01:59 by jmastora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char	*current_directory;

	current_directory = getcwd(NULL, 0);
	if (current_directory)
	{
		ft_printf(1, "%s\n", current_directory);
		free(current_directory);
		return (0);
	}
	else
	{
		perror("pwd");
		return (-1);
	}
}
