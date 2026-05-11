/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 02:46:36 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/29 17:22:08 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dict_node	*ft_dict_set(t_dict *dict, const char *key, void *value)
{
	t_dict_node	*node;

	node = ft_dict_get_node(dict, key);
	if (node)
	{
		node->value = value;
		return (node);
	}
	node = malloc(sizeof(t_dict_node));
	if (!node)
		return (NULL);
	node->key = ft_strdup(key);
	node->value = value;
	node->next = dict->entry;
	dict->entry = node;
	return (node);
}
