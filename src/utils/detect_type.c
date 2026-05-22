/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:30:40 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/05/23 01:19:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// to detect if it's a word

int	is_word(char c)
{
	int	ret;

	ret = (!is_space(c) && !is_operator(c));
	return (ret);
}
