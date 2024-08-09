/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 00:09:49 by alyildiz          #+#    #+#             */
/*   Updated: 2023/11/07 01:33:36 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define SQ '\''
# define DQ '\"'

# include "libft.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/param.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_lst
{
	char			**cmd;
	int				*type;
	struct s_lst	*prev;
	struct s_lst	*left;
	struct s_lst	*right;
	int				check;
}					t_lst;

typedef struct s_ars
{
	int				nb_cmds;
	char			**envp;
	int				pid;
}					t_args;

typedef struct s_minishell
{
	char			*path;
}					t_minishell;

typedef struct s_pars
{
	int				save;
	int				flags;
	int				count;
	char			c;
	int				check;
	int				find;
	int				len;
	int				i;
	char			*cpy;
}					t_pars;

// typedef struct s_pipex
// {
// 	char			**cmds;
// 	int				nbcmd;
// 	char			**envp;
// 	char			*in_file;
// 	char			*out_file;
// 	int				prev;
// 	int				fd[2];
// 	int				pid[1024];
// 	int				here_doc;
// }					t_pipex;

char				*ft_put_neg(char *str);
char				*ft_put_pos(char *str);
# define DEFAULT "\001\033[0;39m\002"
# define GRAY "\001\033[1;90m\002"
# define RED "\001\033[1;91m\002"
# define GREEN "\001\033[1;92m\002"
# define YELLOW "\001\033[1;93m\002"
# define BLUE "\001\033[1;94m\002"
# define MAGENTA "\001\033[1;95m\002"
# define CYAN "\001\033[1;96m\002"
# define WHITE "\001\033[0;97m\002"

typedef struct s_ast
{
}					t_ast;

typedef struct s_here_doc
{
	char			*delimiters;
	int				pipe[2];
}					t_here_doc;

typedef struct s_expansion
{
	char			*str;
	char			*result;
	int				i;
	int				in_single_quote;
	int				in_double_quote;
	int				j;
}					t_expansion;

typedef struct s_execution
{
	int				cmd_count;
	char			**delimiters;
	int				nb_here_doc;
}					t_execution;

typedef struct s_cmd
{
	char			*cmd_str;
	char			**cmd_arg;
	int				*type;
	char			**filename;
}					t_cmd;

typedef struct s_pipex
{
	t_lst			*lst;
	t_cmd			*cmds;
	char			**tab;
	int				nbcmd;
	char			**envp;
	int				prev;
	int				fd[2];
	int				pid[1024];
	int				nb_here_doc;
	bool			in_double_quote;
	bool			in_single_quote;
	t_here_doc		*here_doc;
}					t_pipex;

int					check_direct_command(char *command);
int					type_redirection(char *str);
void				free_bail(t_cmd bail);
char				*ft_strcat(char *dest, char *src);
char				*ft_strcpy(char *dest, char *src);
//			UTILS
int					count_heredoc(char *str);
t_here_doc			*starton_here_doc(void);
t_pipex				*starton(void);
t_here_doc			*here_doc(t_pipex *pipex, char *str);
int					redir_fd_builtins(t_cmd zebi);
int					is_builtins(char *str, t_cmd *cmd);
char				*remove_quote(char *str);
int					exec_builtins(t_pipex *pipex, t_cmd *cmd);
int					exec_builtin(t_cmd *bail, t_pipex *pipex);

t_cmd				parsetout(char **tab);
void				redir_fd(t_cmd zebi, t_pipex *pipex);
int					contains(char *str);
void				execute_command(t_pipex *pipex, int index);
int					is_quotes(char c, int in_single_quote, int in_double_quote);
// PRINTMESSAGE.C
void				ft_printast(t_lst *lst);
void				ft_print_error(int r);

// STARTON.C
t_pipex				*startpipex(void);
t_lst				*startast(void);
t_minishell			*starton_shell(void);
t_args				*starton_args(void);

// UTILS.C
int					ft_strcmp(char *s1, char *s2);
char				*ft_strjoin_egal(char *s1, char *s2);
char				*ft_strjoin_slash(char *s1, char *s2);
char				*ft_strjoin_space(char *s1, char *s2);

//													PARSING
// AST.c
t_lst				*ft_init_tree(t_lst *lst, char **tab);
t_lst				*new_node(char **cmd);
t_lst				*sep_nodetwo(t_lst *parent, char *cmd);
t_lst				*sep_node(t_lst *lst, char *cmd);
t_lst				*new_tree(t_lst *parent, char **cmd, int max);

// UTILS_AST.C
void				ft_tab_free(char **tab);
char				**ft_put_in_tab(char *str);
void				clean_tree(t_lst **lst);
int					ft_spacelen(char *str);
char				*ft_put_space(char *str);

// QUOTE.C
char				*ft_put_neg(char *str);
char				*ft_put_pos(char *str);

// SYNTAX.C

int					synt(char *str);
int					ft_bullfit(t_pars data);
int					ft_quotes(char *str);
int					ft_parenth(char *str);
int					recurs(char *str, int i, int len);
int					syntax(char *str);

// UTILS_SYNTAX.C
int					ft_separator(char *str);
int					separator(char *str);
int					ft_isparenth(char c);
int					ft_count_parenth(char *str);
int					ft_check_parenth(char *str);

// CHECK_SEP.C
int					ft_recurs_parenth(char *str, int i, int len, int last_sep);
int					ft_recurs_and(char *str, int i, int len, int last_sep);
int					ft_recurs_pipe(char *str, int i, int len, int last_sep);
int					ft_recurs_chevr(char *str, int i, int len);

// SLIPED.C
int					count_sliped(char **str);
char				**ft_sliped(char **str);

//													BUILTINS
// FT_CD.c
void				ft_cd(char **str);

// FT_ECHO.C
bool				ft_check_n(char *str);
void				ft_echo(char **args);

// FT_ENV.C
void				ft_env(t_pipex *pipex);

// FT_EXIT.C
int					is_numeric_arg(char *str);
int					ft_exit(char **args);

// FT_EXPORT.C
void				create_var(t_pipex *pipex, char *var_name, char *key);
bool				is_valid_var_name(char *var_name);
void				modify_var(t_pipex *pipex, char *var_name, char *key);
int					ft_export(t_pipex *pipex, char **arguments);

// FT_PWD.C
int					ft_pwd(void);

// FT_UNSET.C
char				*find_env_var(char **envp, const char *key);
void				ft_unset(t_pipex *pipex, char **arguments);

//												EXEC
// char				*join_cmd_until_separator(t_lst *lst, int *i);
int					is_separator(char *str);
int					is_separator2(char *str);
int					sep_counter(t_lst *lst);
// int					is_here_doc(char *cmd);
// int					count_here_docs(t_lst *lst);
// void				handle_redirections(t_lst *lst);
int					is_redirection(char *cmd);

// void				execute_tree(t_lst *lst, t_pipex *pipex);
void				cleanup_cmds(t_pipex *pipex, int *cmd_index);
char				*ft_parenth_check(char *str);
// void				handle_pipe(t_lst *lst, int *i);
// void				handle_background(t_lst *lst, t_pipex *pipex, int *i,
// 						int *cmd_index);
// void				handle_general_command(t_lst *lst, t_pipex *pipex, int *i,
// 						int *cmd_index);
// void				handle_special_commands(t_lst *lst, t_pipex *pipex, int *i,
// 						int *cmd_index);
// void				handle_execution(t_pipex *pipex, int *cmd_index);
// char				**handle_found_here_doc(t_lst *lst, int *i,
// 						char **delimiters, int *count);
// int					handle_input_redirection(char *cmd);
// int					handle_append_redirection(char *cmd);
// int					handle_overwrite_redirection(char *cmd);
// void				initialize_execution(t_lst *lst, t_pipex *pipex,
// 						int *cmd_count, char ***delimiters, int *nb_here_doc);

// void				init_execution_variables(int *i, int *cmd_index,
// 						int *cmd_count, char ***delimiters, int *nb_here_doc);
// int					check_initial_conditions(t_lst *lst, t_pipex *pipex);
// void				loop_through_cmds(t_lst *lst, t_pipex *pipex, int *i,
// 						int *cmd_index);
// void				final_execution_steps(t_pipex *pipex, int cmd_index);
// void				execute_tree(t_lst *lst, t_pipex *pipex);
// AST_EXECUTE.C
void				handle_logical_operators(t_lst *lst, t_pipex *pipex);
void				execute_tree(t_lst *lst, t_pipex *pipex);
void				handle_execution(t_pipex *pipex, int *cmd_index);

// AST_HANDLE_SUP.C
void				handle_redirection(t_lst *lst, int *i, t_pipex *pipex,
						int *cmd_index);
void				handle_pipe(t_lst *lst, int *i);
void				handle_background(t_lst *lst, t_pipex *pipex, int *i,
						int *cmd_index);
void				handle_general_command(t_lst *lst, t_pipex *pipex, int *i,
						int *cmd_index);
void				handle_special_commands(t_lst *lst, t_pipex *pipex, int *i,
						int *cmd_index);

// AST_HANDLE_SUP.C
char				**handle_found_here_doc(t_lst *lst, int *i,
						char **delimiters, int *count);
int					handle_input_redirection(char *filename);
int					handle_append_redirection(char *filename);
int					handle_overwrite_redirection(char *filename);

// AST_INIT_EXEC.C
char				**initialize_delimiters(int num_here_docs);
void				initialize_execution(t_lst *lst, t_pipex *pipex,
						t_execution *exec_info);
char				*join_cmd_until_separator(t_lst *lst, int *start);

// BUILTIN.C
int					ft_strcmp(char *s1, char *s2);
int					is_builtin(char *str);

// ENVIRONMENT.C
void				cpyenv(t_pipex *pipex, char **envp);
char				*get_env_var_value(t_pipex *pipex, char *key);

// EXEC.C
char				**get_true_path(char **env);
char				*get_path(char **env, char *command);
void				redirect(t_pipex *pipex, int i);

// EXPAND.C
int					is_valid_first_char(char c);
int					is_valid_char(char c);
void				init_expand_struct(t_expansion *exp, char *str);
char				*expand_var(t_pipex *pipex, t_expansion *exp);
char				*expand_exit_status(t_expansion *exp);
char				*expand_env_variable(t_pipex *pipex, t_expansion *exp);
char				*expand_env_var(t_pipex *pipex, char *str);

// FT_SPLITEX.C
void				freeloop(char **tab);
int					ft_countdelim(char const *str, char *charset);
char				*ft_strtsub(char const *str, int start, int end);
char				**to_tab(char **tab, char const *s, char *charset,
						int count);
char				**ft_splitex(char *str, char *charset, int *size);

// GET_PROMPT.C
char				*get_user(t_pipex *pipex);
char				*get_current_path(void);
char				*get_prompt(t_pipex *pipex, char *prompt);

// HERE_DOC_UTILS.C
int					count_here_docs(t_lst *lst);
int					is_here_doc(char *cmd);

// HERE_DOC.C
char				*create_filename(int i);
void				write_to_fd(int fd, char *delimiter);
char				*get_word(char *str);
int					get_len_word(char *str);
void				*ft_free(void **ptr);

// PROCESS_SUP.C
void				type_redir(t_pipex *pipex, t_lst *lst, int i);
int					open_fd(t_pipex *pipex, t_lst *lst, int i, int cmd_index);
int					create_pipe(t_pipex *pipex);
void				fork_and_exec(t_pipex *pipex, int i);
void				wait_for_children(t_pipex *pipex);

// PROCESS.C
void				child_process(t_pipex *pipex, int i);
void				parent_process(t_pipex *pipex, int i);
void				execute_in_background(t_pipex *pipex, int index);
void				free_command(char **command);
void				*exec_pipe(t_pipex *pipex);

// SIGNALS.c
void				sig_int(int sig);
void				sig_fork(int sig);
void				sig_quit(int sig);

// UTILS.C
int					find_dollar(char *s1);

// WILDCARD.C
int					matches(char *str, char *pattern);
char				*expand_wildcard_pattern(char *pattern);
char				*expand_pattern_and_concat(char *result, char *expanded);
char				*handle_wildcard(char *str, int *i, char *result, int *j);
char				*expand_wildcard(char *str);

void				free_post_exec(t_pipex *pipex);
void				free_heredoc(t_pipex *pipex);
void				free_child(t_cmd bail, t_pipex *pipex);

#endif