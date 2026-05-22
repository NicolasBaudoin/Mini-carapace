#include "minishell.h"

t_command   *new_command(void)
{
    t_command   *cmd = malloc(sizeof(t_command));
    if (!cmd)
        return (NULL);
    cmd->args = NULL;
    cmd->redir = NULL;
    cmd->next = NULL;
    return (cmd);
}
void	add_back_command(t_command **lst, t_command *new)
{
	t_command	*tmp;

	if (!*lst)
	{
		*lst = new;
		return;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_redir     *new_redir(int type, char *file)
{
    t_redir *redir = malloc(sizeof(t_redir));
    if (!redir)
        return (NULL);
    redir->type = type;
    redir->file = ft_strdup(file);
    redir->next = NULL;
    return (redir);
}

void    add_back_redir(t_redir **lst, t_redir *new)
{
    t_redir *tmp;

    if (!lst || !new)
        return;
    if (!*lst)
    {
        *lst = new;
        return;
    }
    tmp = *lst;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

void    free_redirs(t_redir *redir)
{
    t_redir *tmp;

    while (redir)
    {
        tmp = redir->next;
        free(redir->file);
        free(redir);
        redir = tmp;
    }
}

void    free_commands(t_command **cmds)
{
    t_command   *tmp;
    t_command   *next;
    int         i;

    if (!cmds || !*cmds)
        return;
    tmp = *cmds;
    while (tmp)
    {
        next = tmp->next;
        if (tmp->args)
        {
            i = 0;
            while (tmp->args[i])
                free(tmp->args[i++]);
            free(tmp->args);
        }
        free_redirs(tmp->redir);
        free(tmp);
        tmp = next;
    }
    *cmds = NULL;
}

// ====================== PARSER ======================

t_command   *parser(t_token *tokens, t_data *data)
{
    t_command   *cmds = NULL;
    t_command   *current = NULL;
    t_token     *tmp = tokens;
    int         i;

    while (tmp)
    {
        current = new_command();
        if (!current)
            break;

        // Args counter
        int arg_count = 0;
        t_token *count_tmp = tmp;
        while (count_tmp && count_tmp->type != PIPE)
        {
            if (count_tmp->type == WORD)
                arg_count++;
            count_tmp = count_tmp->next;
        }

        current->args = malloc(sizeof(char *) * (arg_count + 1));
        if (!current->args)
        {
            free(current);
            break;
        }

        i = 0;
        while (tmp && tmp->type != PIPE)
        {
            if (tmp->type == WORD)
            {
                char *expanded = expander(tmp->value, data);
                free(tmp->value);
                tmp->value = expanded;
                current->args[i++] = ft_strdup(tmp->value);
            }
            else if (tmp->type == REDIR_IN || tmp->type == REDIR_OUT ||
                     tmp->type == APPEND || tmp->type == HEREDOC)
            {
                t_token *file_token = tmp->next;
                if (file_token && file_token->type == WORD)
                {
                    char *expanded_file = expander(file_token->value, data);
                    free(file_token->value);
                    file_token->value = expanded_file;

                    t_redir *redir = new_redir(tmp->type, file_token->value);
                    add_back_redir(&current->redir, redir);

                    tmp = tmp->next;  // file_token skip
                }
                else if (tmp->type == HEREDOC)
                {
                    t_token *delim = tmp->next;
                    if (delim && delim->type == WORD)
                    {
                        char *expanded_delim = expander(delim->value, data); // delimiter expansion done in case of heredoc
                        free(delim->value);
                        delim->value = expanded_delim;t_redir *r = new_redir(HEREDOC, delim->value);
                        add_back_redir(&current->redir, r);tmp = tmp->next;  // delimiter skip
                    }
                }
            }
            tmp = tmp->next;
        }

        current->args[i] = NULL;
        add_back_command(&cmds, current);

        if (tmp && tmp->type == PIPE)
            tmp = tmp->next;  // pipe алгасах
    }
    return (cmds);
}