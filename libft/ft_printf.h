/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmastora <jmastora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:35:11 by jmastora          #+#    #+#             */
/*   Updated: 2023/11/05 01:34:01 by jmastora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include   <unistd.h>
# include   <stdarg.h>
# include   <stdint.h>
# include   <limits.h>

int	pf_putchar(int fd, char c);
int	pf_putstr(int fd, char *str);
int	ft_printf(int fd, const char *str1, ...);
int	pf_putnbr_base(int fd, uintptr_t n, uintptr_t base, int minus);
int	ft_spesize(char *s);

#endif
