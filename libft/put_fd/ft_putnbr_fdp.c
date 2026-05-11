/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fdp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:27:21 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/03/13 23:51:37 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fdp(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fdp("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fdp('-', fd);
	}
	if (n > 9)
		ft_putnbr_fdp(n / 10, fd);
	ft_putchar_fdp('0' + n % 10, fd);
}
