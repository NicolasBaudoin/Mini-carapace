/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_low.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <uuenkhba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:24:31 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/03/24 17:50:21 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_hex_calc(unsigned int nb)
{
	unsigned int	i;

	i = 0;
	if (nb > 15)
	{
		i += ft_hex_calc(nb / 16);
		i += ft_hex_calc(nb % 16);
	}
	else
	{
		ft_putchar_fd2(BASE_HEX[nb], 1);
		i++;
	}
	return (i);
}

int	ft_print_hex_low_va(va_list args)
{
	unsigned int	len;
	unsigned int	nb;

	len = 0;
	nb = va_arg(args, unsigned int);
	len = ft_hex_calc(nb);
	return (len);
}
