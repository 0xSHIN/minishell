/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmessage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 01:04:46 by jmastora          #+#    #+#             */
/*   Updated: 2023/11/07 01:43:50 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_e;

void	ft_print_error(int r)
{
	if (r == 1)
		ft_printf(2, " syntax error near unexpected token `)'\n");
	else if (r == 2 || r == 3)
		ft_printf(2, " syntax error near unexpected token `newline\'\n");
	else if (r == 4)
		ft_printf(2, " syntax error near unexpected token `>'\n");
	else if (r == 6 || r == 8 || r == 9 || r == 5 || r == 7)
		ft_printf(2, " syntax error near unexpected token `|'\n");
	else if (r == 12 || r == 13 || r == 14 || r == 15)
		ft_printf(2, " syntax error near unexpected token `&'\n");
	else if (r == 16)
		ft_printf(2, " syntax error near unexpected token `quotes'\n");
	g_e = 2;
}
