/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:26:04 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/02/10 13:55:53 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_fd.h"

char	*gnl_ft_strchr(char *s, char c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (NULL);
}

size_t	gnl_ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	gnl_ft_strcpy(char *dst, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*gnl_ft_strndup(char *str, size_t n)
{
	size_t	i;
	char	*new_str;

	new_str = malloc((n + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*gnl_ft_strjoin(char *s1, char *s2)
{
	size_t	s1_length;
	size_t	s2_length;
	char	*new_str;

	s2_length = gnl_ft_strlen(s2);
	if (!s1)
		return (gnl_ft_strndup(s2, s2_length));
	s1_length = gnl_ft_strlen(s1);
	new_str = malloc((s1_length + s2_length + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	gnl_ft_strcpy(new_str, s1);
	gnl_ft_strcpy(new_str + s1_length, s2);
	free(s1);
	return (new_str);
}
