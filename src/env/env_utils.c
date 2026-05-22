#include "minishell.h"

char	*get_env_value(t_data *data, char *key)
{
	int		i;
	size_t	len;

	if (!data || !data->env || !key || *key == '\0')
		return (ft_strdup(""));

	len = ft_strlen(key);
	i = 0;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], key, len) == 0 && data->env[i][len] == '=')
			return (ft_strdup(data->env[i] + len + 1));
		i++;
	}
	return (ft_strdup(""));
}

int	update_env_var(t_data *data, char *key, char *value)
{
	int		i;
	char	*new_var;
	char	**new_env;
	int		len;

	if (!data || !data->env || !key)
		return (1);

	len = ft_strlen(key);
	i = 0;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], key, len) == 0 && data->env[i][len] == '=')
		{
			free(data->env[i]);
			new_var = ft_strjoin(key, "=");
			new_var = ft_strjoin_free(new_var, value);
			data->env[i] = new_var;
			return (0);
		}
		i++;
	}

	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return (1);

	int j = 0;
	while (j < i)
	{
		new_env[j] = data->env[j];
		j++;
	}

	new_var = ft_strjoin(key, "=");
	new_var = ft_strjoin_free(new_var, value);
	new_env[j++] = new_var;
	new_env[j] = NULL;

	free(data->env);
	data->env = new_env;
	return (0);
}

int	remove_env_var(t_data *data, char *key)
{
	char	**new_env;
	int		i;
	int		j;
	size_t	key_len;

	if (!data || !data->env || !key || *key == '\0')
		return (0);

	key_len = ft_strlen(key);
	i = 0;
	while (data->env[i])
		i++;

	new_env = malloc(sizeof(char *) * i);
	if (!new_env)
		return (1);

	i = 0;
	j = 0;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], key, key_len) == 0 
			&& data->env[i][key_len] == '=')
		{
			free(data->env[i]);
		}
		else
		{
			new_env[j++] = data->env[i];
		}
		i++;
	}
	new_env[j] = NULL;

	free(data->env);
	data->env = new_env;
	return (0);
}

void	free_env(char **env)
{
	int	i = 0;

	if (!env)
		return;

	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}