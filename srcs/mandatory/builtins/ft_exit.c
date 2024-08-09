/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:16:13 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/07 01:45:50 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_e;

void	no_arg(char *nbr)
{
	ft_printf(2, "bash: exit: %s: numeric argument required\n", nbr);
	g_e = 2;
	exit(2);
}

long long	ft_atoll(char *nbr)
{
	unsigned long long int	n;
	int						i;
	int						sign;

	n = 0;
	i = 0;
	sign = 1;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
		i++;
	if (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nbr[i]))
	{
		n = 10 * n + nbr[i++] - '0';
		if (n > LLONG_MAX || (n == LLONG_MAX && sign == -1))
			no_arg(nbr);
	}
	if (!ft_isdigit(nbr[i]) && nbr[i])
		return (0);
	else
		return (n * sign);
}

void	handle_exit(char **args, int i)
{
	long long int	nbr;

	nbr = ft_atoll(args[i + 1]);
	if (nbr == 0)
	{
		g_e = 2;
		printf("exit\n");
		ft_printf(2, "exit: %s: numeric argument required\n", args[i + 1]);
		return (ft_tab_free(args), exit(g_e));
	}
	else if (nbr <= 9223372036854775807 && args[i + 2])
	{
		g_e = 1;
		printf("exit\n");
		ft_printf(2, "bash: exit: too many arguments\n", args[i + 1]);
		return (ft_tab_free(args), exit(g_e));
	}
	else
	{
		printf("exit\n");
		g_e = (unsigned char)nbr;
		return (ft_tab_free(args), exit(g_e));
	}
}

int	ft_exit(char **args)
{
	if (!args || !args[0] || ft_strncmp(args[0], "exit", 4))
		return (0);
	if (!args[1])
	{
		ft_tab_free(args);
		printf("exit\n");
		exit(0);
	}
	handle_exit(args, 0);
	return (0);
}
