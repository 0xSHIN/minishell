/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:06:44 by jmastora          #+#    #+#             */
/*   Updated: 2023/11/06 04:09:55 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putstr(int fd, char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(2, "(null)", 6));
	while (str[i])
	{
		pf_putchar(fd, str[i]);
		i++;
	}
	return (i);
}
