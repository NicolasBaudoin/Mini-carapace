#include "minishell.h"

/*
** envp is an array of strings, where each string is in the format "KEY=VALUE".
*/
void	env_init(t_data *data, char **envp)
{
	int	i;
	int	count;

	if (!envp)
	{
		data->env = malloc(sizeof(char *) * 1);
		if (data->env)
			data->env[0] = NULL;
		return;
	}

	count = 0;
	while (envp[count])
		count++;

	data->env = malloc(sizeof(char *) * (count + 1));
	if (!data->env)
		return;

	i = 0;
	while (i < count)
	{
		data->env[i] = ft_strdup(envp[i]);
		if (!data->env[i])
		{
			while (--i >= 0)
				free(data->env[i]);
			free(data->env);
			data->env = NULL;
			return;
		}
		i++;
	}
	data->env[i] = NULL;
}