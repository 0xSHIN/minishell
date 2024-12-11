/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmastora <jmastora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:20:58 by jmastora          #+#    #+#             */
/*   Updated: 2023/11/05 01:05:20 by jmastora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_quotes(char c, int in_single_quote, int in_double_quote)
{
	if (in_single_quote || in_double_quote)
	{
		return (0);
	}
	return (c == '|' || c == '&' || c == ';');
}

int	ft_separator(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '|' && str[i + 1] == '|') || (str[i] == '&'
			&& str[i + 1] == '&'))
		return (2);
	if (str[i] == '|' || str[i] == '<' || str[i] == '>' || str[i] == '&'
		|| (str[i] == '>' && str[i + 1] == '>') || (str[i] == '<'
			&& str[i + 1] == '<'))
		return (1);
	return (0);
}

int	separator(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '|' && str[i + 1] == '|') || (str[i] == '&'
			&& str[i + 1] == '&') || (str[i] == '>' && str[i + 1] == '>')
		|| (str[i] == '<' && str[i + 1] == '<'))
		return (2);
	if (str[i] == '|' || str[i] == '<' || str[i] == '>' || str[i] == '&'
		|| str[i] == '$')
		return (1);
	return (0);
}

int	ft_isparenth(char c)
{
	if (c == '(' || c == ')')
		return (1);
	return (0);
}

int	ft_count_parenth(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '(')
			count++;
		i++;
	}
	return (count);
}
