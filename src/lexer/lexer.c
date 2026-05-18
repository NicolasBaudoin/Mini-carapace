/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 16:22:23 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/18 15:02:45 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// init_var() to gain lines

static void	init_var(t_token **tokens, t_lexer *lexer, char *input)
{
	*tokens = NULL;
	lexer->state = DEFAULT;
	lexer->input = input;
	lexer->i = 0;
}

// to gain lines

static void	skip_space(t_lexer *lexer)
{
	while (is_space(lexer->input[lexer->i]))
		lexer->i++;
}

// read word is where we handle the unclosed quotes
// it's also where we detect where the word finish so we can tokenize it

int	read_word(t_token **tokens, t_lexer *lexer)
{
	int				start;
	int				ret;
	t_token_info	info;

	start = lexer->i;
	while (lexer->input[lexer->i])
	{
		ret = read_word_loop(lexer, lexer->input[lexer->i]);
		if (ret == 2)
			break ;
		if (ret == 1)
			continue ;
	}
	if (handle_quote_unclosed(lexer))
		return (1);
	info.start = start;
	info.end = lexer->i;
	info.type = WORD;
	if (create_token(tokens, lexer, info))
		return (1);
	return (0);
}

// lexer is the main function to tokenize our elements, it doesn't verify syntax errors
// only quotes unclosed

t_token	*lexer(char *input)
{
	t_token	*tokens;
	t_lexer	lexer;

	init_var(&tokens, &lexer, input);
	while (lexer.input[lexer.i])
	{
		skip_space(&lexer);
		if (!lexer.input[lexer.i])
			break ;
		if (is_operator(lexer.input[lexer.i]))
		{
			if (create_operator_token(&lexer, &tokens))
			{
				free_token(&tokens);
				return (NULL);
			}
		}
		else if (read_word(&tokens, &lexer))
		{
			free_token(&tokens);
			tokens = NULL;
			return (NULL);
		}
	}
	return (tokens);
}
