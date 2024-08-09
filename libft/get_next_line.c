/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:00:05 by jmastora          #+#    #+#             */
/*   Updated: 2023/10/20 10:01:26 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gn_strdel(char **str)
{
	if (*str)
	{
		free(*str);
		*str = 0;
	}
	return (NULL);
}

char	*test(char **str, char *endl, char *buf)
{
	char	*dup;
	char	tmp;

	if (!*str)
		return (gn_strdel(&buf));
	if (endl && endl[1])
	{
		tmp = endl[1];
		endl[1] = '\0';
		dup = gn_strdup(*str);
		endl[1] = tmp;
		gn_strcpy(*str, endl + 1);
		gn_strdel(&buf);
		return (dup);
	}
	dup = gn_strdup(*str);
	gn_strdel(str);
	gn_strdel(&buf);
	return (dup);
}

char	*get_next_line(int fd, int tofree)
{
	static char	*str[1024] = {0};
	char		*buf;
	char		*endl;
	int			r;

	if (tofree)
		return (free(str[fd]), NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (gn_strdel(& buf));
	r = 1;
	endl = gn_strchr(str[fd], '\n');
	while (!endl)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
			return (gn_strdel(&str[fd]), gn_strdel(&buf));
		if (r == 0)
			break ;
		buf[r] = '\0';
		str[fd] = gn_strjoin(str[fd], buf, r);
		endl = gn_strchr(str[fd], '\n');
	}
	return (test(&str[fd], endl, buf));
}
