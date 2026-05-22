#include "minishell.h"

extern int g_status;

/* ====================== ECHO ====================== */
void    mini_echo(t_command *cmd)
{
    int     i = 1;
    int     newline = 1;

    if (cmd->args[1] && ft_strncmp(cmd->args[1], "-n", 3) == 0)
    {
        newline = 0;
        i = 2;
    }

    while (cmd->args[i])
    {
        ft_putstr_fd(cmd->args[i], STDOUT_FILENO);
        if (cmd->args[i + 1])
            ft_putchar_fd(' ', STDOUT_FILENO);
        i++;
    }

    if (newline)
        ft_putchar_fd('\n', STDOUT_FILENO);

    g_status = 0;
}

/* ====================== PWD ====================== */
void    mini_pwd(t_command *cmd)
{
    char    *cwd;

    (void)cmd;
    cwd = getcwd(NULL, 0);
    if (cwd)
    {
        ft_putendl_fd(cwd, STDOUT_FILENO);
        free(cwd);
        g_status = 0;
    }
    else
    {
        perror("minishell: pwd");
        g_status = 1;
    }
}

/* ====================== CD ====================== */
void    mini_cd(t_command *cmd, t_data *data)
{
    char    *dir;

    if (!cmd->args[1])
        dir = get_env_value(data, "HOME");
    else if (ft_strncmp(cmd->args[1], "-", 2) == 0)
        dir = get_env_value(data, "OLDPWD");
    else
        dir = ft_strdup(cmd->args[1]);

    if (!dir || *dir == '\0')
    {
        ft_putstr_fd("minishell: cd: HOME not set\n", STDERR_FILENO);
        g_status = 1;
        free(dir);
        return;
    }

    if (chdir(dir) == -1)
    {
        ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
        ft_putstr_fd(dir, STDERR_FILENO);
        ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
        g_status = 1;
    }
    else
        g_status = 0;

    free(dir);
}

/* ====================== ENV ====================== */
void    mini_env(t_data *data)
{
    int i = 0;

    if (!data || !data->env)
        return;

    while (data->env[i])
    {
        ft_putendl_fd(data->env[i], STDOUT_FILENO);
        i++;
    }
    g_status = 0;
}

/* ====================== EXIT ====================== */
void    mini_exit(t_command *cmd)
{
    int exit_code = 0;

    ft_putendl_fd("exit", STDOUT_FILENO);

    if (cmd->args[1])
        exit_code = ft_atoi(cmd->args[1]);

    exit(exit_code);
}