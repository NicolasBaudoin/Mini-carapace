#include "minishell.h"

char	*get_cmd_path(char *cmd, t_data *data)
{
	char	**paths;
	char	*full_path;
	int		i;

	if (!cmd)
		return (NULL);

	if (cmd[0] == '/' || ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));

	paths = ft_split(get_env_value(data, "PATH"), ':');
	if (!paths)
		return (NULL);

	i = 0;
	while (paths[i])
	{
		full_path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin_free(full_path, cmd);

		if (access(full_path, X_OK) == 0)
		{
			// Free paths array
			while (paths[i])
				free(paths[i++]);
			free(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}

	// Free paths array
	while (paths[i])
		free(paths[i++]);
	free(paths);

	return (NULL);
}