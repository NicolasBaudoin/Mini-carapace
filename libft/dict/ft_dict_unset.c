/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 02:46:53 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/29 17:22:11 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_node(t_dict_node *node)
{
	free(node->key);
	free(node);
}

void	ft_dict_unset(t_dict *dict, const char *key)
{
	t_dict_node	*node;
	t_dict_node	*temp_node;

	node = dict->entry;
	if (node && !ft_strcmp(node->key, key))
	{
		dict->entry = node->next;
		ft_free_node(node);
		return ;
	}
	while (node && node->next)
	{
		temp_node = node->next;
		if (!ft_strcmp(temp_node->key, key))
		{
			node->next = temp_node->next;
			ft_free_node(temp_node);
			return ;
		}
		node = node->next;
	}
}
