#include "minishell.h"

extern int g_status;

/* ====================== SORTING ====================== */
static void sort_env(char **env, int size)
{
    int     i;
    int     j;
    char    *temp;

    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            if (ft_strncmp(env[j], env[j + 1], ft_strlen(env[j]) + 1) > 0)
            {
                temp = env[j];
                env[j] = env[j + 1];
                env[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

/* ====================== PRINT EXPORT ====================== */
static void print_export(char **env)
{
    int i = 0;

    while (env[i])
    {
        ft_putstr_fd("declare -x ", STDOUT_FILENO);
        ft_putendl_fd(env[i], STDOUT_FILENO);
        i++;
    }
}

/* ====================== ADD / UPDATE ====================== */
static int add_or_update_var(t_data *data, char *arg)
{
    char    *key;
    char    *value;
    char    *equal;

    equal = ft_strchr(arg, '=');
    if (!equal)
        return (0);                     // export VAR (without =value)

    key = ft_substr(arg, 0, equal - arg);
    value = ft_strdup(equal + 1);

    update_env_var(data, key, value);

    free(key);
    free(value);
    return (0);
}

/* ====================== EXPORT ====================== */
void    mini_export(t_command *cmd, t_data *data)
{
    char    **env_copy;
    int     i;
    int     count;

    if (!cmd->args[1])  // `export` without arguments → sorted list
    {
        count = 0;
        while (data->env[count])
            count++;

        env_copy = malloc(sizeof(char *) * (count + 1));
        if (!env_copy)
        {
            g_status = 1;
            return;
        }

        i = 0;
        while (i < count)
        {
            env_copy[i] = ft_strdup(data->env[i]);
            i++;
        }
        env_copy[i] = NULL;

        sort_env(env_copy, count);
        print_export(env_copy);

        i = 0;
        while (env_copy[i])
            free(env_copy[i++]);
        free(env_copy);

        g_status = 0;
        return;
    }

    // `export VAR=value` case
    i = 1;
    while (cmd->args[i])
    {
        add_or_update_var(data, cmd->args[i]);
        i++;
    }
    g_status = 0;
}