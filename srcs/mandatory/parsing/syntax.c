/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:58:31 by jmastora          #+#    #+#             */
/*   Updated: 2023/11/06 06:53:22 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_quotes(char *str)
{
	t_pars	data;

	data.find = 0;
	data.check = 0;
	data.i = 0;
	while (str[data.i])
	{
		if (str[data.i] == SQ || str[data.i] == DQ)
		{
			data.find++;
			data.check++;
			data.c = str[data.i++];
			while (str[data.i] && data.check == 1)
			{
				if (str[data.i] == data.c)
					data.check--;
				data.i += data.check;
			}
		}
		if (str[data.i])
			data.i++;
	}
	return (ft_bullfit(data));
}

int	ft_parenth(char *str)
{
	t_pars	data;

	data.find = 0;
	data.check = 0;
	data.i = -1;
	while (str[++data.i])
	{
		if (str[data.i] == '(')
		{
			data.check++;
			data.find = 1;
		}
		if (str[data.i] == ')')
			data.check--;
	}
	if (data.find == 1 || data.check < 0)
	{
		if (ft_check_parenth(str))
			return (0);
		if (data.check == 0)
			return (1);
		return (0);
	}
	return (1);
}

int	recurs(char *str, int i, int len)
{
	static int	last_sep;
	static char	*lstr;

	last_sep = 0;
	if (str != lstr)
	{
		last_sep = 0;
		lstr = str;
	}
	if (str[i] == '&')
		if (ft_recurs_and(str, i, len, last_sep))
			return (ft_recurs_and(str, i, len, last_sep));
	if (str[i] == '|')
		if (ft_recurs_pipe(str, i, len, last_sep))
			return (ft_recurs_pipe(str, i, len, last_sep));
	if (str[i] == '>' || str[i] == '<')
		if (ft_recurs_chevr(str, i, len))
			return (ft_recurs_chevr(str, i, len));
	if (ft_isparenth(str[i]))
		if (ft_recurs_parenth(str, i, len, last_sep))
			return (ft_recurs_parenth(str, i, len, last_sep));
	last_sep = i;
	return (0);
}

int	synt(char *str)
{
	int	retour;

	retour = 0;
	if (ft_quotes(str))
	{
		return (ft_quotes(str));
	}
	str = ft_put_neg(str);
	retour = syntax(str);
	return (retour);
}

int	syntax(char *str)
{
	t_pars	data;

	data.i = 0;
	data.len = ft_strlen(str);
	if (ft_quotes(str))
		return (ft_quotes(str));
	if (!ft_parenth(str))
		return (1);
	while (str[data.i])
	{
		while (str[data.i] && ft_isspace(str[data.i]))
			data.i++;
		while (str[data.i] && !separator(&str[data.i])
			&& !ft_isparenth(str[data.i]))
			data.i++;
		if (separator(&str[data.i]) == 2)
			data.i++;
		if (recurs(str, data.i, data.len))
			return (recurs(str, data.i, data.len));
		while (separator(&str[data.i]) || ft_isparenth(str[data.i]))
			data.i++;
		if (!str[data.i])
			return (0);
	}
	return (0);
}
