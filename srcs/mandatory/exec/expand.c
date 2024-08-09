/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:59:59 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/07 01:43:50 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_e;

static void	handle_double_quote(t_pipex *pipex, t_expansion *exp)
{
	if (exp->str[exp->i] == DQ && !pipex->in_single_quote)
	{
		pipex->in_double_quote = !pipex->in_double_quote;
		exp->result[exp->j++] = exp->str[exp->i++];
	}
}

static void	handle_single_quote(t_pipex *pipex, t_expansion *exp)
{
	if (exp->str[exp->i] == SQ && !pipex->in_double_quote)
	{
		pipex->in_single_quote = !pipex->in_single_quote;
		exp->result[exp->j++] = exp->str[exp->i++];
	}
}

static void	handle_escape_char(t_pipex *pipex, t_expansion *exp)
{
	if (exp->str[exp->i] == '\\' && (pipex->in_double_quote
			|| !pipex->in_single_quote))
	{
		exp->i++;
		exp->result[exp->j++] = exp->str[exp->i++];
	}
}

static void	handle_env_expansion(t_pipex *pipex, t_expansion *exp)
{
	if (!pipex->in_single_quote || pipex->in_double_quote)
	{
		if (exp->str[exp->i] == '$' && exp->str[exp->i + 1] == '?')
			exp->result = expand_exit_status(exp);
		else if (exp->str[exp->i] == '$' && is_valid_first_char(exp->str[exp->i
					+ 1]))
			exp->result = expand_env_variable(pipex, exp);
	}
}

char	*expand_env_var(t_pipex *pipex, char *str)
{
	t_expansion	exp;

	pipex->in_double_quote = 0;
	pipex->in_single_quote = 0;
	if (!str)
		return (NULL);
	init_expand_struct(&exp, str);
	if (!exp.result)
		return (NULL);
	while (exp.str[exp.i])
	{
		handle_double_quote(pipex, &exp);
		handle_single_quote(pipex, &exp);
		handle_escape_char(pipex, &exp);
		handle_env_expansion(pipex, &exp);
		exp.result[exp.j++] = exp.str[exp.i++];
	}
	exp.result[exp.j] = '\0';
	free(str);
	return (exp.result);
}
