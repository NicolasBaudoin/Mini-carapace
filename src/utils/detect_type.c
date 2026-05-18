/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:30:40 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/18 14:57:59 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// to detect if it's a word

int	is_word(char c)
{
	int	ret;

	ret = (!is_space(c) && !is_operator(c));
	return (ret);
}
