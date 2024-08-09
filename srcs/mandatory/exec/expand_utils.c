/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:08:47 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/07 02:12:52 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_e;

int	is_valid_first_char(char c)
{
	return (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	is_valid_char(char c)
{
	return (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'));
}

void	init_expand_struct(t_expansion *exp, char *str)
{
	exp->str = str;
	exp->i = 0;
	exp->j = 0;
	exp->result = ft_calloc(sizeof(char) * ft_strlen(str) + 2, 150);
	if (!exp->result)
		return ;
}

char	*expand_exit_status(t_expansion *exp)
{
	char	*signal;
	char	*new_result;
	size_t	result_size;

	exp->i += 2;
	signal = ft_itoa(g_e);
	result_size = ft_strlen(exp->result) + ft_strlen(signal);
	new_result = ft_calloc(result_size + 1, 5);
	if (!new_result)
	{
		free(signal);
		free(exp->result);
		return (NULL);
	}
	ft_strlcpy(new_result, exp->result, exp->j + 1);
	free(exp->result);
	ft_strlcpy(&new_result[exp->j], signal, ft_strlen(signal) + 1);
	exp->j += ft_strlen(signal);
	free(signal);
	return (new_result);
}

char	*expand_env_variable(t_pipex *pipex, t_expansion *exp)
{
	char	*var;
	char	*new_result;
	size_t	result_size;

	exp->i++;
	var = expand_var(pipex, exp);
	if (!var)
		return (exp->result);
	result_size = ft_strlen(exp->result) + ft_strlen(var) + 2;
	new_result = ft_calloc(result_size, sizeof(char));
	if (!new_result)
		return (free(exp->result), NULL);
	ft_strlcpy(new_result, exp->result, exp->j + 1);
	free(exp->result);
	ft_strlcpy(&new_result[exp->j], var, ft_strlen(var) + 1);
	exp->j += ft_strlen(var);
	return (new_result);
}
