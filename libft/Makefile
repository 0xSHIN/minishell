# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 17:42:45 by jmastora          #+#    #+#              #
#    Updated: 2023/11/03 21:57:51 by alyildiz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_isalpha.c ft_isdigit.c ft_atoi.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
		ft_strdup.c ft_toupper.c ft_tolower.c ft_strchr.c ft_memset.c ft_bzero.c ft_strncmp.c \
		ft_strrchr.c ft_strlcpy.c ft_calloc.c ft_memcmp.c ft_memcpy.c ft_memchr.c ft_memmove.c \
		ft_strlcat.c ft_strnstr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_substr.c ft_strmapi.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_striteri.c \
		get_next_line.c get_next_line_utils.c ft_isspace.c ft_isparenthesis.c ft_isseparator.c \
		ft_printf.c  ft_putchar.c  ft_putnbr_base.c  ft_putstr.c slip.c \

BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c  \
	  ft_lstclear.c ft_lstiter.c ft_lstmap.c \

NAME	= libft.a
 
OBJS		= ${SRCS:.c=.o} ${ADDED:.c=.o} 
 
OBJS_BONUS	= ${BONUS:.c=.o}
 
.c.o	:
		cc -Wall -Wextra -Werror -c $< -o ${<:.c=.o} -g3
 
all : ${NAME}
 
${NAME} : ${OBJS}
		ar rcs ${NAME} ${OBJS}
 
bonus	: $(OBJS) $(OBJS_BONUS)
		ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

clean :
		rm -f ${OBJS} ${OBJS_BONUS} $(OBJS_GNL) $(OBJS_PRINTF)
 
fclean : clean
		rm -f ${NAME}

so:
	cc -nostartfiles -fPIC -Wall -Wextra -Werror $(SRCS)
	cc -nostartfiles -shared -o libft.so $(OBJS)

re : fclean all
 
.PHONY : all bonus clean fclean re

