/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_char_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 17:34:26 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/18 14:58:29 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// here we can simplify the functions, but fow now we can deal with it
// so it detect what type of char it is

int	is_operator(char c)
{
	int	ret;

	ret = (c == '|' || c == '<' || c == '>');
	return (ret);
}

int	is_space(char c)
{
	int	ret;

	ret = (c == ' ' || c == '\t' || c == '\n');
	return (ret);
}

int	is_quote(char c)
{
	return (c == '"' || c == '\'');
}

int	is_append(char *input, int start)
{
	if (input[start] == '>' && input[start + 1] == '>')
		return (1);
	else
		return (0);
}

int	is_heredoc(char *input, int start)
{
	if (input[start] == '<' && input[start + 1] == '<')
		return (1);
	else
		return (0);
}
