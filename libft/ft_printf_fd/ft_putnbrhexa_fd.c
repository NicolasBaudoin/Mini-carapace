/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 02:03:59 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/03/13 16:23:37 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

void	ft_putnbrhexa_fd(int fd, unsigned int v, int in_lowercase, int *count)
{
	const char	hexa_lowercase[] = "0123456789abcdef";
	const char	hexa_uppercase[] = "0123456789ABCDEF";

	if (v > 15)
		ft_putnbrhexa_fd(fd, v / 16, in_lowercase, count);
	if (in_lowercase)
		ft_putchar_fd(fd, ((char *)hexa_lowercase)[v % 16], count);
	else
		ft_putchar_fd(fd, ((char *)hexa_uppercase)[v % 16], count);
}
