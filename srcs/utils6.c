#include "../incs/minishell.h"

void	piper(t_minishell *ms, int i)
{
	int	j;

	if (i)
		j = 0;
	else
		j = 1;
	dup2(ms->pipe[i], i);
	close(ms->pipe[j]);
}

void	quote_expander(t_minishell *ms, char *res)
{
	if (!ms->quote)
		ms->quote = ms->args[ms->i][ms->j];
	else
	{
		if (ms->args[ms->i][ms->j] != ms->quote)
			res[++ms->x] = ms->args[ms->i][ms->j];
		else
			ms->quote = 0;
	}
}
