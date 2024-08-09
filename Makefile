NAME            =    minishell

LIBFT            =    libft.a

DIR_SRCS        =    srcs/mandatory

DIR_BONUS        =    srcs/bonus

DIR_OBJS        =    objs

SRCS_NAMES        =		exec/exec.c exec/exec_utils.c exec/expand_utils.c exec/free.c exec/process_sup.c exec/ast_utils_exec.c exec/ast_init_exec.c exec/ast_execute.c exec/expand.c exec/wildcard.c exec/here_doc.c exec/here_doc_utils.c exec/process.c exec/signals.c exec/ft_splitex.c exec/builtin.c exec/get_prompt.c exec/environment.c \
						builtins/ft_pwd.c builtins/ft_cd.c builtins/ft_env.c builtins/ft_echo.c builtins/ft_exit.c builtins/ft_export.c builtins/ft_unset.c \
						parsing/ast.c parsing/utils_ast.c parsing/le_s_2syntax.c parsing/sliped.c parsing/syntax.c parsing/utils_syntax.c parsing/quote.c parsing/printmessage.c parsing/check_sep.c main.c \
						utils/starton.c utils/utils.c \

SRCS_NAMES_B    =    	

OBJS_NAMES        =    ${SRCS_NAMES:.c=.o}

OBJS_NAMES_B    =    ${SRCS_NAMES_B:.c=.o}

SRCS            =    $(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))

SRCS_B            =    $(addprefix $(DIR_BONUS)/,$(SRCS_NAMES_B))

OBJS            =    $(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

OBJS_B            =    $(addprefix $(DIR_OBJS)/,$(OBJS_NAMES_B))

HEAD            =    -Ilibft -Iinclude

CC                =    cc

CFLAGS            =    -Wall -Werror -Wextra

MAKEFLAGS        =    --no-print-directory

all                :    ${NAME}

$(NAME): $(DIR_OBJS) $(OBJS)
	@ make -s -C  libft
	@ mv libft/libft.a .
	@ $(CC) ${HEAD} $(CFLAGS) $(OBJS)  -lreadline ${LIBFT} -o $(NAME)
	@ echo "MINISHELL"  | toilet -f future -F border --metal

$(OBJS) : $(DIR_OBJS)/%.o : $(DIR_SRCS)/%.c | $(DIR_OBJS)
	@ mkdir -p $(dir $@)
	@ $(CC) -g3 $(CFLAGS) $(HEAD) -c $< -o $@ 

$(DIR_OBJS):
	@ mkdir -p $(DIR_OBJS)



leaks : all
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --suppressions=ignore.txt ./minishell


clean:
	@ make clean -s -C libft
	@ rm -rf ${DIR_OBJS}4
	@ rm -rf ${OBJS}

fclean:    clean
	@ make fclean -s -C libft
	@ rm -rf ${LIBFT}
	@ rm -rf ${NAME}

re:    fclean all

stop:
	rm -f ${NAME}

.PHONY:    all clean fclean re bonus
# .SILENT:
