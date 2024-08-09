/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmastora <jmastora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:41:57 by jmastora          #+#    #+#             */
/*   Updated: 2023/05/24 21:46:46 by jmastora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int			i;
	long int	n2;

	n2 = n;
	i = 0;
	if (n2 == 0)
		return (1);
	if (n2 < 0)
	{
		n2 = n2 * -1;
		i++;
	}
	while (n2 > 0)
	{
		n2 = n2 / 10 ;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{	
	char	*c;
	int		size;
	long	nb;

	nb = n;
	size = ft_len(n);
	c = ft_calloc(size + 1, sizeof(char));
	if (!(c))
		return (NULL);
	if (nb == 0)
		c[0] = nb + '0';
	if (nb < 0)
	{
		nb = nb * -1;
		c[0] = '-';
	}
	size--;
	while (nb > 0)
	{	
		c[size--] = ((nb % 10) + 48);
		nb = nb / 10;
	}
	return (c);
}
