/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:19:49 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/03/22 21:09:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ns;
	size_t	i;

	if (!s || !f)
		return (NULL);
	ns = ft_strdup(s);
	if (!ns)
		return (NULL);
	i = 0;
	while (ns[i])
	{
		ns[i] = f(i, s[i]);
		i++;
	}
	return (ns);
}
/* char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tab_strmapi;
	unsigned int	i;
	unsigned int	t;

	if (!s || !f)
		return (NULL);
	t = ft_strlen(s);
	i = 0;
	tab_strmapi = ft_calloc(t + 1, sizeof(char));
	if (!tab_strmapi)
		return (NULL);
	while (s[i])
	{
		tab_strmapi[i] = f(i, s[i]);
		i++;
	}
	tab_strmapi[i] = '\0';
	return (tab_strmapi);
}
*/