#include "minishell.h"

int	is_operator(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	is_append(char *input, int start)
{
	return (input[start] == '>' && input[start + 1] == '>');
}


int	is_heredoc(char *input, int start)
{
	return (input[start] == '<' && input[start + 1] == '<');
}