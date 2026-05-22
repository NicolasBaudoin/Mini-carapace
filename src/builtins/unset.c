#include "minishell.h"

extern int g_status;

/*
** mini_unset - Unset environment variables based on command arguments
*/
void    mini_unset(t_command *cmd, t_data *data)
{
    int i = 1;

    if (!cmd->args[1])      // `unset` without arguments
    {
        g_status = 0;
        return;
    }

    while (cmd->args[i])
    {
        // Only valid identifiers (starting with letter or underscore) can be unset
        if (cmd->args[i][0] && (ft_isalpha(cmd->args[i][0]) || cmd->args[i][0] == '_'))
        {
            remove_env_var(data, cmd->args[i]);
        }
        i++;
    }

    g_status = 0;   // unset always returns 0 even if variable not found, as per bash behavior
}