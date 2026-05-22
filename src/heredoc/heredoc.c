#include "minishell.h"

extern int g_status;

static char *expand_heredoc_line(char *line, t_data *data)
{
    if (!line)
        return (NULL);
    return (expander(line, data));
}

char    *get_heredoc_input(char *delimiter, t_data *data)
{
    char    *line;
    char    *input;
    char    *expanded;

    input = ft_strdup("");
    if (!input)
        return (NULL);

    while (1)
    {
        line = readline("> ");
        if (!line)  // Ctrl + D
        {
            ft_putstr_fd("\n", STDOUT_FILENO);
            free(input);
            return (NULL);
        }

        // Delimiter таарвал stop
        if (ft_strncmp(line, delimiter, ft_strlen(delimiter) + 1) == 0)
        {
            free(line);
            break;
        }

        expanded = expand_heredoc_line(line, data);
        free(line);

        char *tmp = ft_strjoin(input, expanded);
        free(expanded);
        free(input);
        input = ft_strjoin(tmp, "\n");
        free(tmp);
    }
    return (input);
}

int handle_heredoc(t_command *cmd, t_data *data)
{
    t_redir *redir = cmd->redir;
    int     pipe_fd[2];
    char    *content;

    while (redir)
    {
        if (redir->type == HEREDOC)
        {
            if (pipe(pipe_fd) == -1)
            {
                perror("minishell: pipe");
                return (1);
            }

            setup_heredoc_signals();

            content = get_heredoc_input(redir->file, data);

            reset_signals();

            if (content)
            {
                write(pipe_fd[1], content, ft_strlen(content));
                free(content);
            }

            close(pipe_fd[1]);
            dup2(pipe_fd[0], STDIN_FILENO);
            close(pipe_fd[0]);
        }
        redir = redir->next;
    }
    return (0);
}