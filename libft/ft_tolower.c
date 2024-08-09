/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmastora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 19:00:28 by jmastora          #+#    #+#             */
/*   Updated: 2023/05/24 21:09:08 by jmastora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int character)
{
	if (character >= 65 && character <= 90)
	{
		return (character + 32);
	}
	else
		return (character);
}
