/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:26:08 by jmastora          #+#    #+#             */
/*   Updated: 2023/11/06 06:53:12 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_recurs_parenth(char *str, int i, int len, int last_sep)
{
	while (str[last_sep] && ft_isspace(str[last_sep]))
		last_sep++;
	if (i > 0 && str[i] != ')')
		i--;
	while (i > last_sep && (ft_isspace(str[i]) || !(ft_isparenth(str[i])
				|| !ft_isseparator(str[i]))))
		i--;
	if (str[last_sep] != '(' && (!ft_isseparator(str[i])
			&& !ft_isparenth(str[i])))
		return (10);
	if (!str[len--])
		while (len > i && ft_isspace(str[len]))
			len--;
	if (str[i] == ')' && i == len)
		return (0);
	if (str[i] == ')')
		i++;
	while (str[i] && !ft_isparenth(str[i]) && !ft_isseparator(str[i]))
		i++;
	if (!ft_isseparator(str[i]) && !ft_isparenth(str[i]) && i != len)
		return (11);
	return (0);
}

int	ft_recurs_and(char *str, int i, int len, int last_sep)
{
	if (str[len - 1] == '&')
		return (12);
	if (!str[len])
		len--;
	while (len > 0 && (ft_isspace(str[len]) || str[len] == ')'
			|| str[len] == '('))
		len--;
	if (str[len] == '&')
		return (13);
	if (str[i + 1] == '&' || separator(&str[i + 1]))
		return (14);
	while (str[i] == '&' && i > 0)
		i--;
	while (i > 0 && (ft_isspace(str[i]) || str[i] == ')' || str[i] == '('))
		i--;
	if (i == last_sep && (ft_isspace(str[i]) || separator(&str[i])
			|| str[i] == '(' || str[i] == ')'))
		return (15);
	return (0);
}

int	ft_recurs_pipe(char *str, int i, int len, int last_sep)
{
	if (str[len - 1] == '|')
		return (6);
	if (!str[len])
		len--;
	while (len > 0 && (ft_isspace(str[len]) || str[len] == ')'
			|| str[len] == '('))
		len--;
	if (str[len] == '|')
		return (7);
	if (str[i + 1] == '|' || separator(&str[i + 1]))
		return (8);
	while (str[i] == '|' && i > 0)
		i--;
	while (i > 0 && (ft_isspace(str[i]) || str[i] == ')' || str[i] == '('))
		i--;
	if (i == last_sep && (ft_isspace(str[i]) || separator(&str[i])
			|| str[i] == '(' || str[i] == ')'))
		return (9);
	return (0);
}

int	ft_recurs_chevr(char *str, int i, int len)
{
	if ((str[i] == '>' && str[i + 1] == '<') || (str[i] == '<' && str[i
				+ 1] == '>'))
		return (3);
	if (str[i] == '>' && str[i + 1] == '>' && str[i - 1] == '>')
		return (4);
	if (str[len - 1] == '>' || str[len - 1] == '<')
		return (2);
	if (i < len && separator(&str[i]))
		i++;
	while (str[i] && !separator(&str[i]))
		i++;
	if (!str[i] || separator(&str[i]))
		i--;
	while (i > 0 && ft_isspace(str[i]))
		i--;
	if (str[i] == '>' || str[i] == '<')
		return (4);
	return (0);
}
