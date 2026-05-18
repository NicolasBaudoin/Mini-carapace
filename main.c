/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 01:07:51 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/18 14:57:18 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status = 0;
// status pour les signaux des fonctions et arret programme
// add
// parser(tokens)
// execution(tokens);
// =====================
// t_token is where we store the info of the tokens we recognize,
// sow e know it's a word or pipe etc
/*typedef struct s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
}				t_token;*/

void	mishell_is_working(char *input)
{
	t_token	*tokens;
	t_token	*curr;

	tokens = lexer(input);
	curr = tokens;
	if (!tokens)
		return ;
	// this while is to see what's store in tokens
	while (curr)
	{
		printf("value = [%s], type = %d\n", curr->value, curr->type);
		curr = curr->next;
	}
	free_token(&tokens);
}

int	main(void)
{
	char	*input;

	setup_signals();
	while (1)
	{
		// readline is where we can do a beautiful prompt later
		input = readline("Mishell> ");
		if (input == NULL)
		{
			// this is where we handle CTRL + D
			// clear history to exit properly
			rl_clear_history();
			printf("\nExiting...\n");
			return (1);
		}
		// add history so arrow up and down works
		add_history(input);
		// a function to manage the step of minishell
		mishell_is_working(input);
		// free at the end so we have no leaks
		free(input);
	}
	return (0);
}
