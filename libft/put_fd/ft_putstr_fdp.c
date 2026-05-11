/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fdp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:24:23 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/03/18 20:58:55 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fdp(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar_fdp(*s, fd);
		s++;
	}
}
/*
#include "libft.h"

void	ft_putstr_fdp(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
	*/
