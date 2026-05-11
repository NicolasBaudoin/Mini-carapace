/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:48:05 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/02/10 15:49:05 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin_gb(char *str1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!str1)
	{
		str1 = malloc(sizeof(char) + 1);
		if (!str1)
			return (0);
		str1[0] = 0;
	}
	str = (char *)malloc(sizeof(char) * ft_strlen(str1) + ft_strlen(s2) + 1);
	if (!str)
		return (ft_free_s(&str1));
	i = -1;
	while (str1[++i])
		str[i] = str1[i];
	c = -1;
	while (s2[++c])
		str[i + c] = s2[c];
	str[i + c] = '\0';
	free(str1);
	return (str);
}

size_t	ft_strlen_gb(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gb(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (0);
}

char	*ft_substr_gb(char *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!str)
		return (0);
	if (start > ft_strlen(str))
	{
		res = malloc(sizeof(char) * (1));
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (ft_strlen(str) - start < len)
		len = ft_strlen(str) - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (start < ft_strlen(str) && i < len && str[start])
		res[i++] = str[start++];
	res[i] = '\0';
	return (res);
}
