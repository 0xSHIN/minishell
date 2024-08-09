/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmastora <jmastora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:02:01 by jmastora          #+#    #+#             */
/*   Updated: 2023/08/21 18:29:39 by jmastora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *theString)
{
	int		i;
	int		sign;
	int		value;

	i = 0;
	value = 0;
	sign = 1;
	while ((theString[i] >= 9 && theString[i] <= 13) || (theString[i] == 32))
		i++;
	if (theString[i] == '+' || theString[i] == '-')
	{
		if (theString[i] == '-')
			return (-1);
		i++;
	}
	while (theString[i] >= '0' && theString[i] <= '9')
	{
		value = value * 10 + (theString[i] - 48);
		i++;
	}
	return (value * sign);
}
