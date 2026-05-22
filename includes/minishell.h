#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

/* ====================== GLOBAL ====================== */
extern int	g_status;
extern int	g_signal;

/* ====================== ENUMS ====================== */
typedef enum e_token_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	APPEND,
	HEREDOC
}	t_token_type;

typedef enum e_state
{
	DEFAULT,
	SINGLE_QUOTE,
	DOUBLE_QUOTE
}	t_state;

/* ====================== STRUCTS ====================== */

typedef struct s_redir
{
	int				type;
	char			*file;
	struct s_redir	*next;
}	t_redir;

typedef struct s_command
{
	char			**args;
	t_redir			*redir;
	struct s_command	*next;
}	t_command;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

typedef struct s_lexer
{
	t_state		state;
	char		*input;
	int			i;
}	t_lexer;

typedef struct s_token_info
{
	int				start;
	int				end;
	t_token_type	type;
}	t_token_info;

typedef struct s_data
{
	char	**env;
}	t_data;

/* ====================== FUNCTIONS ====================== */

// Main
int		main(int ac, char **av, char **envp);

// Signals
void	setup_signals(void);
void	setup_heredoc_signals(void);
void	reset_signals(void);
void	handle_sigint(int sig);
void	handle_sigint_heredoc(int sig);

// ====================== LEXER ======================
t_token	*lexer(char *input);
t_token	*new_token(char *value, t_token_type type);
void	add_back_token(t_token **lst, t_token *new);
int		create_token(t_token **tokens, t_lexer *lexer, t_token_info info);
void	free_token(t_token **tokens);

int		read_word(t_token **tokens, t_lexer *lexer);
int		read_word_loop(t_lexer *lexer, char c);
int		create_operator_token(t_lexer *lexer, t_token **tokens);
int		handle_default_state(t_lexer *lexer, char c);
int		handle_quote_state(t_lexer *lexer, char c);
int		handle_quote_unclosed(t_lexer *lexer);

int		is_operator(char c);
int		is_space(char c);
int		is_append(char *input, int start);
int		is_heredoc(char *input, int start);

// ====================== PARSER ======================
t_command	*parser(t_token *tokens, t_data *data);
t_command	*new_command(void);
void		add_back_command(t_command **lst, t_command *new);
void		free_commands(t_command **cmds);

// ====================== EXPANDER ======================
char	*expander(char *str, t_data *data);

// ====================== EXECUTOR ======================
void	executor(t_command *cmds, t_data *data);
int		exec_single_command(t_command *cmd, t_data *data);
void	exec_pipe_commands(t_command *cmds, t_data *data);
int		is_builtin(char *cmd);
void	exec_builtin(t_command *cmd, t_data *data);
void	setup_redirections(t_redir *redir);
int		has_heredoc(t_command *cmd);
int		handle_heredoc(t_command *cmd, t_data *data);

// ====================== HEREDOC ======================
char	*get_heredoc_input(char *delimiter, t_data *data);

// ====================== BUILTINS ======================
void	mini_echo(t_command *cmd);
void	mini_pwd(t_command *cmd);
void	mini_cd(t_command *cmd, t_data *data);
void	mini_env(t_data *data);
void	mini_export(t_command *cmd, t_data *data);
void	mini_unset(t_command *cmd, t_data *data);
void	mini_exit(t_command *cmd);

// ====================== ENVIRONMENT ======================
void	env_init(t_data *data, char **envp);
char	*get_env_value(t_data *data, char *key);
int		update_env_var(t_data *data, char *key, char *value);
int		remove_env_var(t_data *data, char *key);
char	*get_cmd_path(char *cmd, t_data *data);
void	free_env(char **env);

// ====================== UTILS ======================
char	*ft_strndup(const char *s, int start, int end);
char	*ft_strjoin_free(char *s1, char *s2);
void	free_redirs(t_redir *redir);

#endif