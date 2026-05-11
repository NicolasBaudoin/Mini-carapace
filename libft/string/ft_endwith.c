/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endwith.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:33:14 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/29 17:20:47 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_endwith(char *str, char *end)
{
	size_t	i;
	size_t	end_length;
	size_t	str_length;

	if (!str || !end)
		return (0);
	i = 0;
	end_length = ft_strlen(end);
	str_length = ft_strlen(str);
	while (str[str_length - i - 1] == end[end_length - i - 1]
		&& i < end_length && i < str_length)
		i++;
	return (end[i] == '\0');
}
