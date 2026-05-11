/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 02:02:22 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/03/13 17:24:29 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

void	ft_putaddr_fd(int fd, size_t v, int prefix, int *count)
{
	const char	hexa_lowercase[] = "0123456789abcdef";

	if (v == 0 && prefix)
	{
		ft_putstr_fd(fd, "(nil)", count);
		return ;
	}
	if (prefix)
		ft_putstr_fd(fd, "0x", count);
	if (v > 15)
		ft_putaddr_fd(fd, v / 16, 0, count);
	ft_putchar_fd(fd, ((char *)hexa_lowercase)[v % 16], count);
}
