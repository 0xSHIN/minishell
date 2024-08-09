/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:09:04 by jmastora          #+#    #+#             */
/*   Updated: 2023/10/16 08:13:42 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_choic(int fd, intptr_t n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (pf_putstr(fd, "-2147483648"));
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
		i = 1;
	}
	return (pf_putnbr_base(fd, n, 10, 0) + i);
}

int	pf_choice(int fd, va_list *var, const char c)
{
	void	*p;

	if (c == 'c')
		return (pf_putchar(fd, va_arg(*var, int)));
	else if (c == 's')
		return (pf_putstr(fd, va_arg(*var, char *)));
	else if (c == '%')
		return (pf_putchar(fd, '%'));
	else if (c == 'X' || c == 'x')
		return (pf_putnbr_base(fd, va_arg(*var, unsigned int), 16, 'x' == c));
	else if (c == 'd' || c == 'i')
		return (pf_choic(fd, va_arg(*var, int)));
	else if (c == 'u')
		return (pf_putnbr_base(fd, va_arg(*var, unsigned int), 10, 0));
	else if (c == 'p')
	{
		p = (va_arg(*var, void *));
		if (p == 0)
			return (pf_putstr(fd, "(nil)"));
		return (pf_putstr(fd, "0x") + pf_putnbr_base(fd, (uintptr_t)p, 16, 1));
	}
	return (0);
}

int	ft_printf(int fd, const char *str, ...)
{
	int		i;
	int		count;
	va_list	var;

	i = 0;
	count = 0;
	va_start(var, str);
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count = count + pf_choice(fd, &var, str[i++]);
		}
		else
			count = count + pf_putchar(fd, str[i++]);
	}
	va_end(var);
	return (count);
}
