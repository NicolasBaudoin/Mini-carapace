/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:12:52 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/03/22 21:12:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*tab;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len >= ft_strlen(s + start))
		len = ft_strlen(s + start);
	tab = malloc(sizeof(char) * (len) + 1);
	if (!tab)
		return (NULL);
	while (0 < len)
	{
		tab[i++] = s[start++];
		len--;
	}
	tab[i] = '\0';
	return (tab);
}
/* char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab_substr;
	size_t	i;
	size_t	s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		tab_substr = ft_calloc(1, 1);
		return (tab_substr);
	}
	if (len > s_len - start)
		len = s_len - start;
	tab_substr = ft_calloc(len + 1, sizeof(char));
	if (!tab_substr)
		return (NULL);
	while (i < len && s[start + i])
	{
		tab_substr[i] = s[start + i];
		i++;
	}
	return (tab_substr);
}
*/