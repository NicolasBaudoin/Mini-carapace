/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:35:53 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/03/22 21:11:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*pch;

	pch = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			pch = (char *)&s[i];
		i++;
	}
	if (s[i] == (char)c)
		pch = (char *)&s[i];
	return (pch);
}
/* char	*ft_strchr(const char *s, int c)
{
	char	cc;
	char	*p;

	cc = (char)c;
	p = (char *)s;
	while (*p)
	{
		if (*p == cc)
			return (p);
		p++;
	}
	if (cc == '\0')
		return (p);
	return (NULL);
}
*/
/* char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	char	*p;
	char	*result;

	cc = (char)c;
	p = (char *)s;
	result = NULL;
	while (*p)
	{
		if (*p == cc)
			result = p;
		p++;
	}
	if (cc == '\0')
		return (p);
	return (result);
}
*/