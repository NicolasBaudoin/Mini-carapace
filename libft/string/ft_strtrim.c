/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:13:47 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/03/22 21:12:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issep(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_startinit(int i, char const *s1, char const *set)
{
	while (ft_issep(s1[i], set))
		i++;
	return (i);
}

static int	ft_endinit(int j, char const *s1, char const *set)
{
	if (j < 0)
		j = 0;
	while (ft_issep(s1[j], set))
		j--;
	return (j);
}

static int	ft_strlen1(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tab;
	int		i;
	int		j;
	int		k;

	i = ft_startinit(0, s1, set);
	j = ft_endinit(ft_strlen(s1) - 1, s1, set);
	k = 0;
	if (i >= ft_strlen1(s1))
		return (ft_strdup(""));
	tab = malloc(sizeof(char) * ((j - i) + 2));
	if (!tab || !s1)
		return (NULL);
	while (i <= j)
	{
		tab[k] = s1[i];
		k++;
		i++;
	}
	tab[k] = '\0';
	return (tab);
}
/* int	ft_charset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_start_s1(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_charset(s1[i], set))
		i++;
	return (i);
}

int	ft_end_s1(char const *s1, char const *set, size_t start_len)
{
	size_t	i;

	i = ft_strlen(s1);
	while (i > start_len && ft_charset(s1[i - 1], set))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tab_strtrim;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = ft_start_s1(s1, set);
	end = ft_end_s1(s1, set, start);
	i = 0;
	tab_strtrim = ft_calloc(end - start + 1, sizeof(char));
	if (!tab_strtrim)
		return (NULL);
	while (start < end)
	{
		tab_strtrim[i] = s1[start];
		i++;
		start++;
	}
	tab_strtrim[i] = '\0';
	return (tab_strtrim);
}
*/