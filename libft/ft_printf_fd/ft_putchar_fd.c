/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 02:03:41 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/03/13 16:22:58 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

void	ft_putchar_fd(int fd, char c, int *count)
{
	int	length;

	length = write(fd, &c, 1);
	if (length > 0)
		*count += length;
}
