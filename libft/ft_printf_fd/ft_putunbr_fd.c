/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 02:04:15 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/03/13 16:24:11 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

void	ft_putunbr_fd(int fd, unsigned int nb, int *count)
{
	if (nb > 9)
		ft_putunbr_fd(fd, nb / 10, count);
	ft_putchar_fd(fd, nb % 10 + '0', count);
}
