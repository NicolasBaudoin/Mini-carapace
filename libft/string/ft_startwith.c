/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startwith.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:34:03 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/29 17:21:13 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_startwith(char *str, char *start)
{
	size_t	i;

	if (!str || !start)
		return (0);
	i = 0;
	while (str[i] == start[i] && str[i])
		i++;
	return (start[i] == '\0');
}
