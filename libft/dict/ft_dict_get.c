/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 02:45:59 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/29 17:22:00 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dict_get(t_dict *dict, const char *key)
{
	t_dict_node	*node;

	node = ft_dict_get_node(dict, key);
	if (node)
		return (node->value);
	return (NULL);
}
