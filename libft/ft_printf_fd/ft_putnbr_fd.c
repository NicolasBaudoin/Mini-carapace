/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 02:02:40 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/03/13 16:23:19 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

void	ft_putnbr_fd(int fd, long int nb, int *count)
{
	if (nb == -2147483648)
	{
		ft_putstr_fd(fd, "-2147483648", count);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_fd(fd, '-', count);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr_fd(fd, nb / 10, count);
	ft_putchar_fd(fd, nb % 10 + '0', count);
}
