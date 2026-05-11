/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 02:45:43 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/29 17:31:04 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_node(t_dict_node *node)
{
	free(node->key);
	free(node);
}

void	ft_dict_clear(t_dict **dict)
{
	t_dict_node	*node;
	t_dict_node	*temp_node;

	node = (*dict)->entry;
	while (node)
	{
		temp_node = node;
		node = node->next;
		ft_free_node(temp_node);
	}
	free(*dict);
	*dict = NULL;
}
