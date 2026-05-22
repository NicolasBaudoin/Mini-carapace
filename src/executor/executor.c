#include "minishell.h"

extern int g_status;

/* ====================== UTILS ====================== */

static int	count_commands(t_command *cmds)
{
	int	count = 0;

	while (cmds)
	{
		count++;
		cmds = cmds->next;
	}
	return (count);
}

static void	close_all_pipes(int *pipes, int nb_pipes)
{
	int	i = 0;

	while (i < nb_pipes * 2)
	{
		close(pipes[i]);
		i++;
	}
}

static void	restore_std(int saved_in, int saved_out)
{
	dup2(saved_in, STDIN_FILENO);
	dup2(saved_out, STDOUT_FILENO);
	close(saved_in);
	close(saved_out);
}
int	has_heredoc(t_command *cmd)
{
	t_redir *r = cmd->redir;
	while (r)
	{
		if (r->type == HEREDOC)
			return (1);
		r = r->next;
	}
	return (0);
}
/* ====================== BUILTIN ====================== */

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);

	if (ft_strncmp(cmd, "echo", 5) == 0)
		return (1);
	if (ft_strncmp(cmd, "pwd", 4) == 0)
		return (1);
	if (ft_strncmp(cmd, "cd", 3) == 0)
		return (1);
	if (ft_strncmp(cmd, "env", 4) == 0)
		return (1);
	if (ft_strncmp(cmd, "export", 7) == 0)
		return (1);
	if (ft_strncmp(cmd, "unset", 6) == 0)
		return (1);
	if (ft_strncmp(cmd, "exit", 5) == 0)
		return (1);

	return (0);
}

void	exec_builtin(t_command *cmd, t_data *data)
{
	if (ft_strncmp(cmd->args[0], "echo", 5) == 0)
		mini_echo(cmd);
	else if (ft_strncmp(cmd->args[0], "pwd", 4) == 0)
		mini_pwd(cmd);
	else if (ft_strncmp(cmd->args[0], "cd", 3) == 0)
		mini_cd(cmd, data);
	else if (ft_strncmp(cmd->args[0], "env", 4) == 0)
		mini_env(data);
	else if (ft_strncmp(cmd->args[0], "export", 7) == 0)
		mini_export(cmd, data);
	else if (ft_strncmp(cmd->args[0], "unset", 6) == 0)
		mini_unset(cmd, data);
	else if (ft_strncmp(cmd->args[0], "exit", 5) == 0)
		mini_exit(cmd);
}

/* ====================== REDIRECTIONS ====================== */

void	setup_redirections(t_redir *redir)
{
	int	fd;

	while (redir)
	{
		if (redir->type == REDIR_IN)
		{
			fd = open(redir->file, O_RDONLY);
			if (fd < 0)
				perror("minishell: input");
			else
				dup2(fd, STDIN_FILENO);
		}
		else if (redir->type == REDIR_OUT)
		{
			fd = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (fd < 0)
				perror("minishell: output");
			else
				dup2(fd, STDOUT_FILENO);
		}
		else if (redir->type == APPEND)
		{
			fd = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
			if (fd < 0)
				perror("minishell: append");
			else
				dup2(fd, STDOUT_FILENO);
		}
		if (fd >= 0)
			close(fd);
		redir = redir->next;
	}
}

/* ====================== SINGLE COMMAND ====================== */

int	exec_single_command(t_command *cmd, t_data *data)
{
	int		saved_in;
	int		saved_out;
	pid_t	pid;
	char	*cmd_path;

	if (!cmd || !cmd->args || !cmd->args[0])
		return (1);

	saved_in = dup(STDIN_FILENO);
	saved_out = dup(STDOUT_FILENO);

	if (has_heredoc(cmd))
		handle_heredoc(cmd, data);

	setup_redirections(cmd->redir);

	if (is_builtin(cmd->args[0]))
	{
		exec_builtin(cmd, data);
		restore_std(saved_in, saved_out);
		return (g_status);
	}

	pid = fork();
	if (pid == 0)
	{
		cmd_path = get_cmd_path(cmd->args[0], data);
		if (!cmd_path)
		{
			ft_putstr_fd("minishell: command not found: ", STDERR_FILENO);
			ft_putendl_fd(cmd->args[0], STDERR_FILENO);
			exit(127);
		}
		execve(cmd_path, cmd->args, data->env);
		perror("minishell: execve");
		exit(126);
	}
	else if (pid > 0)
	{
		waitpid(pid, &g_status, 0);
		if (WIFEXITED(g_status))
			g_status = WEXITSTATUS(g_status);
	}

	restore_std(saved_in, saved_out);
	return (g_status);
}

/* ====================== PIPE COMMANDS ====================== */

void	exec_pipe_commands(t_command *cmds, t_data *data)
{
	t_command	*curr = cmds;
	int			nb_cmds = count_commands(cmds);
	int			*pipes;
	pid_t		*pids;
	int			i;

	if (nb_cmds == 1)
	{
		exec_single_command(cmds, data);
		return;
	}

	pipes = malloc(sizeof(int) * (nb_cmds - 1) * 2);
	pids = malloc(sizeof(pid_t) * nb_cmds);
	if (!pipes || !pids)
		return;

	for (i = 0; i < nb_cmds - 1; i++)
		pipe(&pipes[i * 2]);

	i = 0;
	while (curr)
	{
		pids[i] = fork();
		if (pids[i] == 0)
		{
			if (i > 0)
				dup2(pipes[(i - 1) * 2], STDIN_FILENO);
			if (i < nb_cmds - 1)
				dup2(pipes[i * 2 + 1], STDOUT_FILENO);

			close_all_pipes(pipes, nb_cmds - 1);

			if (has_heredoc(curr))
				handle_heredoc(curr, data);
			setup_redirections(curr->redir);

			if (is_builtin(curr->args[0]))
			{
				exec_builtin(curr, data);
				exit(g_status);
			}
			else
			{
				char *cmd_path = get_cmd_path(curr->args[0], data);
				if (!cmd_path)
					exit(127);
				execve(cmd_path, curr->args, data->env);
				exit(126);
			}
		}
		curr = curr->next;
		i++;
	}

	close_all_pipes(pipes, nb_cmds - 1);
	free(pipes);

	for (i = 0; i < nb_cmds; i++)
		waitpid(pids[i], &g_status, 0);

	if (WIFEXITED(g_status))
		g_status = WEXITSTATUS(g_status);

	free(pids);
}

/* ====================== MAIN EXECUTOR ====================== */

void	executor(t_command *cmds, t_data *data)
{
	if (!cmds)
		return;
	exec_pipe_commands(cmds, data);
}