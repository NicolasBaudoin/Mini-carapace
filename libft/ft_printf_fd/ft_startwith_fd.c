/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startwith.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 02:03:07 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/03/13 16:24:17 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	printf_ft_startwith_fd(const char *s, const char *val)
{
	size_t	i;

	i = 0;
	while (s[i] == val[i] && val[i] && s[i])
		i++;
	if (val[i] == '\0')
		return (1);
	return (0);
}
