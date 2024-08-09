/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmastora <jmastora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:18:49 by jmastora          #+#    #+#             */
/*   Updated: 2023/08/02 21:56:46 by jmastora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5

# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd, int tofree);
char	*gn_strdel(char **str);
int		gn_strlen(char *str);
char	*gn_strjoin(char *str, char *buf, int r);
char	*gn_strcpy(char *dest, char *src);
char	*gn_strchr(char *str, char c);
char	*gn_strdup(char *src);

#endif