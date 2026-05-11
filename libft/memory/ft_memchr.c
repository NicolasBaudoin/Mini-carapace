/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:50:32 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/03/24 23:05:39 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned int	i;

	s1 = (unsigned char *) s;
	i = 0;
	while (n > i)
	{
		if (s1[i] == (unsigned char) c)
			return ((void *) &s1[i]);
		i++;
	}
	return (NULL);
}
