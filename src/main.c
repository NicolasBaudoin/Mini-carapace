#include "minishell.h"

int	g_status = 0;

static void	init_data(t_data *data, char **envp)
{
	env_init(data, envp);
}

static void	free_data(t_data *data)
{
	if (data && data->env)
		free_env(data->env);
}

int	main(int ac, char **av, char **envp)
{
	char		*input;
	t_data		data;
	t_token		*tokens;
	t_command	*cmds;

	(void)av;
	if (ac != 1)
	{
		ft_putendl_fd("minishell: no arguments needed", STDERR_FILENO);
		return (1);
	}

	init_data(&data, envp);
	setup_signals();

	while (1)
	{
		input = readline("Mishell> ");
		if (!input)
		{
			ft_putendl_fd("exit", STDOUT_FILENO);
			rl_clear_history();
			break;
		}

		if (*input)
			add_history(input);

		tokens = lexer(input);
		if (tokens)
		{
			cmds = parser(tokens, &data);
			if (cmds)
			{
				executor(cmds, &data);
				free_commands(&cmds);
			}
			free_token(&tokens);
		}

		free(input);
	}

	free_data(&data);
	return (0);
}